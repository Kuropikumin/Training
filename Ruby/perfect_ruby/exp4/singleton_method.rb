class Foo
end

foo = Foo.new
bar = Foo.new

def bar.hogehoge
  puts 'hogehoge called'
end

bar.hogehoge
foo.hogehoge # NoMethodError
