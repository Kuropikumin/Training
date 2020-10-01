def greet(name, message = 'hi')
  puts "#{message}, #{name}"
end

def hoge(name, *)
  puts name
end

def greet_twice(name, first, second)
  puts "#{first}, #{name}."
  puts "#{second}, #{name}."
end

greet 'Tom'
greet 'Bob', 'hoge'
greet 'Alice', nil

hoge 'tom', 'bob', 'Alice'

a = ['first', 'second']

greet_twice 'Bob', *a
