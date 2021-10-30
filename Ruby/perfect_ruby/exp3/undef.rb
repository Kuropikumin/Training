def greet
  puts 'Hello'
end

greet
puts 'hogehoge'

undef greet, puts

# greet           # undefined local variable or method `greet' for main:Object (NameError)
# puts 'fugafuga' # undefined method `puts' for main:Object (NoMethodError)
