class MyClass
  attr_accessor :length

  def self.pair
    [new, new]
  end
end

puts MyClass.pair

a = MyClass.pair

a[0].length = 1
a[1].length = 2

puts "#{a[0].length} : #{a[1].length}"
