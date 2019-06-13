import socket, string

#some user data, change as per your taste
SERVER = 'localhost'
PORT = 18344
NICKNAME = 'test_py'
CHANNEL = '#ryuji-m_test'

#open a socket to handle the connection
IRC = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

#open a connection with the server
def irc_conn():
    IRC.connect((SERVER, PORT))

#simple function to send data through the socket
def send_data(command):
    IRC.send(command + '\n')

#join the channel
def join(channel):
    send_data("JOIN %s" % channel)

#send login data (customizable)
def login(nickname, username='user', password = None, realname='Pythonist', hostname='Helena', servername='Server'):
    send_data("USER %s %s %s %s" % (username, hostname, servername, realname))
    send_data("NICK " + nickname)

def topic_message(message='no message'):
    my_message = "USER " + CHANNEL + " %s" % (message)
    my_message += "\n"
    send_data(my_message)

irc_conn()
login(NICKNAME)
join(CHANNEL)
topic_message("hogehoge")
