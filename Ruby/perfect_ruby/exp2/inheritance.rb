class Parent
  def hello
    puts 'This is Super Object method'
  end

  def override
    puts 'This is Super Object override method'
  end
end

class Child < Parent
  def hi
    puts 'This is Child Object'
  end
  def override
    puts 'This is Child Object override method'
  end
end

chi = Child.new
chi.hello
chi.hi
chi.override
