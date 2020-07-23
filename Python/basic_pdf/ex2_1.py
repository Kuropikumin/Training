# x の平方根を求める
x    = 2 # 初期値
rnew = x # 比較値

for i in range( 10 ):
    r1 = rnew
    r2 = x/r1
    rnew = ( r1 + r2 )/2
    print( i + 1, "回目：", r1, rnew, r2 )
