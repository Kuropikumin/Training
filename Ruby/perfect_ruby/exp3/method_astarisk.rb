def single_asta(*n3, n1: 'tom', n2: 'bob')
  puts n1
  puts n2
  n3.each do |hoge|
    puts "n3 : #{hoge}"
  end
end

def double_asta(n1: 'tom', n2: 'bob', **n3)
  puts n1
  puts n2
  puts n3
  # n3.each do |hoge, fuga|
  #   puts "n3 : #{hoge} > #{fuga}"
  # end
end

def asta(hoge = 0, *fuga)
  puts hoge
  fuga.each do |a|
    puts "fuga : #{a}"
  end
end

name = ['Arice', 'cobe', 'dave']
name2 = {n4: 'Arice', n5: 'cobe', n6: 'dave'}
single_asta(*name, n1: 'Tom', n2: 'Bob')
double_asta(**name2, n1: 'Tom', n2: 'Bob')
