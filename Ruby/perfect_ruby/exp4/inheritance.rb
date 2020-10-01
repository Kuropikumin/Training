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
b.greet # $B7Q>5(B

puts a.test # initialize
puts b.test # initialize $B$N(Boverride

puts Child::PARENT # class$BJQ?t$N7Q>5(B

a.self_introduction
#b.self_introduction # Error($B0z?t$,;XDj$5$l$F$$$J$$$?$a(B)
b.self_introduction("fuga")
c.self_introduction("piyo")
