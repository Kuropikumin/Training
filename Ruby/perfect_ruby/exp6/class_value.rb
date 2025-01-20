class ClassValue
  # クラス変数の定義方法
  # クラス変数は initialize や インスタンスメソッドでなくてもアクセス可能
  @@class_value = 'class value'  

  # クラス変数のアクセス、変更方法
  def class_value
    @@class_value
  end

  def class_value= ( value )
    @@class_value = value
  end
end

class InstanceValue
  # インスタンス変数は、initialize or インスタンスメソッドでのみアクセス可能
  def initialize
    @instance_value = 'instance value'
  end

  def instance_value
    @instance_value
  end

  def instance_value= ( value )
    @instance_value = value
  end
end

class ClassInstanceValue
  # クラスインスタンス変数は、initializeやインスタンスメソッドでなくてもアクセス可能
  # クラスメソッドでアクセスする
  @class_instance_value = 'class instance value'
  
  def self.class_instance_value
    @class_instance_value
  end

  def self.class_instance_value= ( value )
    @class_instance_value = value
  end
end


test = ClassValue.new
p test.class_value
test.class_value = 'hogehoge'
p test.class_value

test = InstanceValue.new
p test.instance_value
test.instance_value = 'fugafuga'
p test.instance_value

test = ClassInstanceValue
# p test.class_instance_value              # NoMethodError
# p test.class_instance_value = 'piyopiyo' # NoMethodError
# p test.class_instance_value              # NoMethodError
p ClassInstanceValue.class_instance_value
p ClassInstanceValue.class_instance_value = 'piyopiyo'
p ClassInstanceValue.class_instance_value



class DiffClassInstanceValue
  @class_instance_value = 'class instance value'
  @@class_value         = 'class value'

  def initialize
    @instance_value = 'instance value'
  end

  def instance_method
    puts "==================== instance_method ===================="
    print "@instance_value = "
    p @instance_value    
    print "@class_instance_value = "
    p @class_instance_value
    print "@@class_value = "
    p @@class_value
  end

  def self.class_method
    puts "==================== class method ===================="
    print "@instance_value = "
    p @instance_value    
    print "@class_instance_value = "
    p @class_instance_value
    print "@@class_value = "
    p @@class_value
  end
end


puts "\nクラス変数、インスタンス変数、クラスインスタンス変数へのアクセス方法の違い"
test = DiffClassInstanceValue.new
test.instance_method
DiffClassInstanceValue.class_method

class ChildDiff < DiffClassInstanceValue 
  def instance_method
    puts "==================== instance_method ===================="
    print "@instance_value = "
    p @instance_value    
    print "@class_instance_value = "
    p @class_instance_value
    print "@@class_value = "
    p @@class_value
  end

  def self.class_method
    puts "==================== class method ===================="
    print "@instance_value = "
    p @instance_value    
    print "@class_instance_value = "
    p @class_instance_value
    print "@@class_value = "
    p @@class_value
  end
end

puts "\n継承されるかどうかの確認"
test = ChildDiff.new
test.instance_method
ChildDiff.class_method