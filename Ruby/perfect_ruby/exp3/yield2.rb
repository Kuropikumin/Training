def return_array
  puts 'before yield'
  yield [1, 2, 3]
  puts 'after yield'
end

hoge = [1, 2, 3]

return_array do |num|
  puts 'before block'
  puts num
  puts 'after block'
end
