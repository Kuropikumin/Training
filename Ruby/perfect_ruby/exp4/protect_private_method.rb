class MyClass
  def process
    puts "process..."
  end

  def protected_process
    puts "protected process..."
  end

  def private_process
    puts "private process..."
  end

  protected :protected_process
  private   :private_process
end

a = MyClass.new
a.process
# a.protected_process #Error(NoMethodError)
# a.private_process   #Error(NoMethodError)
