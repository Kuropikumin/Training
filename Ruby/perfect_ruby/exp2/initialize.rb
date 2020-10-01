class Ruler
  attr_accessor :length

  def initialize(length)
    @length = length
  end
end

ruler = Ruler.new(30)
puts ruler.length
