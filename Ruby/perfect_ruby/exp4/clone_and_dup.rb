class MyClass
  attr_accessor :length
  
  def initialize( length )
    self.length = length
  end
end

r1 = MyClass.new( 30 )
r2 = r1.clone
r3 = r1.dup

p r1
p r2
p r3

r1.length = 20

p r1
p r2
p r3

p r1.frozen?
r1.freeze
p r1.frozen?

r4 = r1.clone
r5 = r1.dup

p r4
p r4.frozen?
p r5
p r5.frozen?
