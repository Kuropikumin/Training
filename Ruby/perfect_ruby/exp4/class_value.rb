class Monster
  @@num = 0
  attr_reader :name
  def initialize(name)
    @name = name
    @@num += 1
  end

  def get_num
    @@num
  end
end

m1 = Monster.new('hoge')
m2 = Monster.new('fuga')

puts m1.name
puts m2.name
puts m1.get_num
