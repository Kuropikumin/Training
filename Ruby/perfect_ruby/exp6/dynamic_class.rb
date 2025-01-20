hoge = 10

DynamicClass = Class.new do | klass |
  p hoge # hogeの値を参照できる
end

class StaticClass
  p hoge # hogeの値を参照できない
end

fuga = StaticClass.new