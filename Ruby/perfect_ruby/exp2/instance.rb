class Ruler
  def length=( val )
    @length = val
  end

  def length
    @length
  end
end

ruler = Ruler.new
puts ruler.length

ruler.length = 10
puts ruler.length

