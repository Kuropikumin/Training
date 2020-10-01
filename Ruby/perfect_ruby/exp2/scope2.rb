greeting = "Hello, "
people   = ['Alice', 'Tom']

people.each do |name|
  puts greeting + name
end

puts name # NameError発生(eachブロックで定義したnameはローカル変数のためスコープ外)
