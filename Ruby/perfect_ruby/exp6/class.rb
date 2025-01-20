class_object = nil

ThirdClass = Class.new do | my_class |
  class_object = my_class
  my_class == self

  def hello
    :hello
  end
end

p class_object == ThirdClass

p third_class_instance = ThirdClass.new
p third_class_instance.hello
