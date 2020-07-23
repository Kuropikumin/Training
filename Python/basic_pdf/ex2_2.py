# x の平方根を求める
x    = 1000 # 初期値
rnew = x # 比較値

for i in range( 100000 ):
    r1 = rnew
    r2 = x/r1
    rnew = ( r1 + r2 )/2

print( r1, rnew, r2 )
