class MyClass
  def (p self).class_method
    :class_method
  end
end

puts "MyClass.class_method"
p MyClass.class_method

def MyClass.class_method
    :singleton_method
end

puts "change MyClass.class_method"
p MyClass.class_method