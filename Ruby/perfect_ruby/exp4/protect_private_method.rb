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

  def private_process_for_instance
    private_process
  end

  protected :protected_process
  private   :private_process
end

a = MyClass.new
a.process
# a.protected_process # protected method `protected_process' called for #<MyClass:0x0000561f6d902738> (NoMethodError)
# a.private_process   # private method `private_process' called for #<MyClass:0x0000559f36d82950> (NoMethodError)
a.private_process_for_instance