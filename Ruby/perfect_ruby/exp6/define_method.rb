class MyClass
  define_method :instance_method, -> { :instance_method }
end

obj = MyClass.new
p obj.instance_method

module FirstIncludeModule
  def same_name_method
    :first_included_method
  end
end

module SecondncludeModule
  def same_name_method
    :second_included_method
  end
end

class MyClass2
  include FirstIncludeModule
  include SecondncludeModule
end

object = MyClass2.new
p object.same_name_method