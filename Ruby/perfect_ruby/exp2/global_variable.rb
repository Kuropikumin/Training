$foo = 'foo is global variable!'

def print_foo
  puts $foo
end

puts $foo
print_foo
