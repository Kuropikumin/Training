foo = 'foo is toplevel variable'

def print_foo
  puts foo # NameError: undefined local variable or method `foo' for main:Object
end

puts foo
print_foo
