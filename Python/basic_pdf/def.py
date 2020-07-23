a = 10
b = 5
a = 'hoge'

def f():
    global b
    c = a*2
    b = c

f()
print( b, a )
