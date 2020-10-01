class MyClass
  def initialize
    puts 'Do initialize...'
    @baked = false
  end

  def baked?
    @baked
  end

  def bake!
    @baked = true
    self
  end
end

b = MyClass.new
puts b.baked?
puts b.bake!
puts b.baked?

