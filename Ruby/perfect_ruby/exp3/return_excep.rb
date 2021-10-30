def my_exception_check(error_name, error_message)
  raise error_name, error_message
end

a = 'begin before raise process'
b = 'begin after raise process'
c = 'rescue process'
d = 'ensure process'

return_value =
  begin
    a
    raise LoadError, 'LoadErrorです'
    b
  rescue StandardError => e
    puts e.class
    c
  ensure
    d
  end

puts "return_value : #{ return_value }"
