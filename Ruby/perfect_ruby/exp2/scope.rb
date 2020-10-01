foo = 'foo is toplevel variable'

def print_foo
  puts foo # NameError発生（fooが定義されていないため）
end

puts foo
print_foo
