class Ruler
  attr_accessor :length

  def self_length
    self.length = 30
    length =20
  end
end

ruler = Ruler.new
ruler.length = 10
ruler.self_length
puts ruler.length
