greeter = Proc.new { |name|
  puts "Hello, #{name}"
}

greeter.call 'Proc'
greeter.call 'Bob'

