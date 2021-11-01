class MyClass
  attr_accessor :length

  def initialize( length )
    self.length = length
  end

  def ==( other )
    length == other.length
  end
end

r1 = MyClass.new( 30 )
r2 = MyClass.new( 20 )
r3 = MyClass.new( 30 )

p r1
p r2
p r3

p r1 == r2 # override Object.==
p r1 == r3 # override Object.==
p r1 != r2 # Object.!= is using Object.==

p r1.frozen?
r1.freeze
p r1.frozen?
# r1.extend Enumerable # can't modify frozen object: #<MyClass:> (FrozenError)