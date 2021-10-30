greeting = "Hello, "
people   = [ 'Alice', 'Tom' ]

people.each do | name |
  puts greeting + name
end

puts name # NameError: undefined local variable or method `name' for main:Object
