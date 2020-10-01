def my_sample
  puts 'before yield!'
  puts yield # if block_given?
  puts 'after yield!'
end

my_sample do
  puts 'yield!!!'
  5523
end

# my_sample # LocalJumpError(yieldで実行するためのブロックを渡していないため) 
          # -> block_given?を使ってblockを渡したか確認すると、Errorを避けられる

