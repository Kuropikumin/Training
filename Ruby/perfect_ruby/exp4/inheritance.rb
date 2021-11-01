class Parent
  PARENT = 'hogehoge'
  attr_accessor :test
  def initialize
    @test = 'parent'
  end

  def greet
    puts 'Hi'
  end

  def self_introduction
    puts 'My Name is hogehoge'
  end
end

class Child < Parent
  def initialize
    @test = 'child'
  end

  def self_introduction( name )
    puts "My Name is #{ name }"
  end
end

class GrandChild < Child
  def self_introduction( name )
    super
    puts "Nice to meet you!"
  end
end

a = Parent.new
b = Child.new
c = GrandChild.new
puts Child.superclass
a.greet
b.greet # Parent.greet 

puts a.test # Parent initialize
puts b.test # Child initialize

puts Child::PARENT # class constant num

a.self_introduction
# b.self_introduction # wrong number of arguments (given 0, expected 1) (ArgumentError)
b.self_introduction("fuga")
c.self_introduction("piyo")
