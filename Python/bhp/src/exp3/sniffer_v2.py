# coding: UTF-8
import ipaddress
import os
import socket
import struct
import sys
import threading
import time

# スキャン対象のサブネット
SUBNET  = 'xxx.xxx.xxx.xxx/xxx'
# ICMPレスポンスのチェック用マジック文字列
MESSAGE = 'PYTHONRULES!'

class IP:
    def __init__( self, buff = None ):
        header   = struct.unpack( '<BBHHHBBH4s4s', buff )
        self.ver = header[0] >> 4
        self.ihl = header[0] & 0xF

        self.tos          = header[1]
        self.len          = header[2]
        self.id           = header[3]
        self.offset       = header[4]
        self.ttl          = header[5]
        self.protocol_num = header[6]
        self.sum          = header[7]
        self.src          = header[8]
        self.dst          = header[9]

        # IPアドレスを可読な形で変数に格納
        self.src_address = ipaddress.ip_address( self.src )
        self.dst_address = ipaddress.ip_address( self.dst )

        # プロトコルの低数値を名称にマッピング
        self.protocol_map = { 1: "ICMP", 6: "TCP", 17: "UDP" }
        try:
            self.protocol = self.protocol_map[self.protocol_num]
        except Exception as e:
            print( '%s No protocol for %s' % ( e, self.protocol_num ) )
            self.protocol = str( self.protocol_num )

class ICMP:
    def __init__( self, buff ):
        header    = struct.unpack( '<BBHHH', buff )
        self.type = header[0]
        self.code = header[1]
        self.sum  = header[2]
        self.id   = header[3]
        self.seq  = header[4]

def udp_sender():
    with socket.socket( socket.AF_INET, socket.SOCK_DGRAM ) as sender:
        for ip in ipaddress.ip_network( SUBNET ).hosts():
            sender.sendto( bytes( MESSAGE, 'utf8' ), ( str( ip ), 65212 ) )

class Scanner:
    def __init__( self, host ):
        self.host = host
        if os.name == 'nt':
            socket_protocol = socket.IPPROTO_IP
        else:
            socket_protocol = socket.IPPROTO_ICMP

        self.socket = socket.socket( socket.AF_INET, socket.SOCK_RAW, socket_protocol )
        self.socket.bind( ( host, 0 ) )

        self.socket.setsockopt( socket.IPPROTO_IP, socket.IP_HDRINCL, 1 )
        print('hitting promiscuous mode...')

        if os.name == 'nt':
            self.socket.ioctl( socket.SIO_RCVALL, socket.RCVALL_ON )

    def sniff( self ):
        hosts_up = set( [str( self.host ) + ' *'] )
        try:
            while True:
                # パケットの読み込み
                raw_buffer = self.socket.recvfrom( 65535 )[0]
                # バッファの最初の20バイトからIP構造体を作成
                ip_header = IP( raw_buffer[0:20] )
    
                # ICMPであればそれを処理
                if ip_header.protocol == "ICMP":
                    # ICMPの位置を計算
                    offset      = ip_header.ihl*4
                    buff        = raw_buffer[offset: offset + 8] 
                    icmp_header = ICMP( buff )
                    # コードとタイプが3であるか（UDPで到達不可）をチェック
                    if icmp_header.code == 3 and icmp_header.type == 3:
                        if ipaddress.ip_address( ip_header.src_address ) in ipaddress.IPv4Network( SUBNET ):
                            # マジック文字列を含むか確認
                            if raw_buffer[len( raw_buffer ) - len( MESSAGE ):] == bytes( MESSAGE, 'utf8' ):
                                tgt = str( ip_header.src_address )
                                if tgt != self.host and tgt not in hosts_up:
                                    hosts_up.add( str( ip_header.src_address ) )
                                    print( 'Host Up: %s' % ( tgt ) )
        except KeyboardInterrupt:
            # Windowsの場合はプロミスキャスモードを無効化
            if os.name == 'nt':
                sniffer.ioctl( socket.SIO_RCVALL, socket.RCVALL_OFF )
            print( '\nUser interrupted.' )
            if hosts_up:
                print( 'Summary: Hosts up on %s' % ( SUBNET ) )
            for host in sorted( hosts_up ):
                print( host )
            print( '' )
            sys.exit()

if __name__ == '__main__':
    if len( sys.argv ) == 2:
        host = sys.argv[1]
    else:
        host = '192.168.0.1'
    s = Scanner( host )
    time.sleep( 5 )
    t = threading.Thread( target = udp_sender )
    t.start()
    s.sniff()