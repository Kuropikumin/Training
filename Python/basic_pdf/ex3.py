# x の平方根を求める
x    = 2 # 初期値
rnew = x # 比較値
diff = rnew - x/rnew

if( diff < 0 ): diff = -diff

while( diff > 10E-6 ):
    r1 = rnew
    r2 = x/r1
    rnew = ( r1 + r2 )/2
    print( r1, rnew, r2 )
    diff = r1 - r2
    if( diff < 0 ): diff = -diff

print( r1, rnew, r2 )
