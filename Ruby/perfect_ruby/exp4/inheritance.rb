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

  def self_introduction(name)
    puts "My Name is #{name}"
  end
end

class GrandChild < Child
  def self_introduction(name)
    super
    puts "Nice to meet you!"
  end
end

a = Parent.new
b = Child.new
c = GrandChild.new
puts Child.superclass
a.greet
b.greet # 継承

puts a.test # initialize
puts b.test # initialize のoverride

puts Child::PARENT # class変数の継承

a.self_introduction
#b.self_introduction # Error(引数が指定されていないため)
b.self_introduction("fuga")
c.self_introduction("piyo")
