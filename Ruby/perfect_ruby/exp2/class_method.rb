class Ruler
  attr_accessor :length

  def self.pair
    [Ruler.new, Ruler.new]
  end
end

puts Ruler.pair
