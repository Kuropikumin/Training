CONSTANT_FOO = 'CONSTANT_FOO is constant'
puts CONSTANT_FOO

CONSTANT_FOO = 'bar' # warning発生(定数に再代入をしようとしているため)
puts CONSTANT_FOO    # 定数に再代入をする場合、warningは発生するがエラーにはならない

def mymethod
  CONSTANT_BAR = 'bar' # dynamic constant assigmentError発生（メソッド内では定数は定義できないため）
  puts CONSTANT_BAR
end
