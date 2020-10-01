module MyFunctions
  def my_module_function
    puts 'my module function called!'
  end

  def module_a
    puts 'module a called!'
  end

  module_function :my_module_function
end

MyFunctions.my_module_function
# MyFunctions.module_a # NoMethodError
o = Object.new
o.extend MyFunctions

o.module_a
o.my_module_function # NoMethodError
