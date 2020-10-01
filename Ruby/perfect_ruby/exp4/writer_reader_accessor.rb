class MyClass
  attr_accessor :my_access
  attr_reader   :my_read
  attr_writer  :my_write
end

a = MyClass.new
a.my_access = 0
puts a.my_access

#a.my_read = 1 # Error
puts a.my_read

a.my_write = 2
# puts a.my_write #Error

