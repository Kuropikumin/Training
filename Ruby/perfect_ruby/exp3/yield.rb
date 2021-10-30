def my_sample
  puts 'before yield!'
  puts yield # if block_given?
  puts 'after yield!'
end

my_sample do
  puts 'yield!!!'
  break 3300
  5523
end

# my_sample # no block given (yield) (LocalJumpError)

