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

p MyClass.pair
p MyClass.trio
