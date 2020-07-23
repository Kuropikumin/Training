import math

while True:
    x = input( "正の数値を入力してください\n終了したい場合は \"end\" を入力してください > " )

    if( x == "end" ): break

    try:
        x = float( x )
    except ValueError:
        print( x, "は数値に変換できません" )
        continue
    except:
        print( "予期せぬエラーが発生しました" )
        exit()
    if( x <= 0 ):
        print( x, "は正の値ではありません" )
        continue

    rnew = x
    while True:
        r1   = rnew
        r2   = x/r1
        rnew = ( r1 + r2 )/2
        print( r1, rnew, r2 )
        diff = abs( r1 - r2 )
        if diff <= 1.0E-6: break

