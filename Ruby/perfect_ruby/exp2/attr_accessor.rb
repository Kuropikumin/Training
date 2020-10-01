class Ruler
  attr_accessor :length

  def puts_length
    puts length
  end
end

ruler = Ruler.new
ruler.length = 10
ruler.puts_length
