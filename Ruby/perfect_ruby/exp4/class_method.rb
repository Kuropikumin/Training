class MyClass
  class << self
    def pair
      [new, new]
    end

    def trio
      [new, new, new]
    end
  end
end

puts MyClass.pair
puts MyClass.trio
