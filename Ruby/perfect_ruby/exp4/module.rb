module MyModule
  def greet_to(name)
    puts "Hello, #{name}"
  end

  class Hoge
    def greet_to
      puts 'Hoge greet_to'
    end
  end
end

module ModuleA
  def my_module
    puts 'module a'
  end
end

class IncludeClass
  include ModuleA
end

class ExtendClass
  extend ModuleA
end

class Foo
  include MyModule
end

a = Foo.new
a.greet_to('hoge')
b = MyModule::Hoge.new
b.greet_to

c = IncludeClass.new
d = ExtendClass.new
c.my_module
# d.my_module # NoMethodError
# IncludeClass.my_module # NoMethodError
ExtendClass.my_module
