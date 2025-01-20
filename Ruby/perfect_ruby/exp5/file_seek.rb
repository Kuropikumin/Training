File.open 'text/test_num.txt' do |f|
  puts "Seek 10"
  f.seek 10
  puts f.pos.to_s + " : " + f.readline

  puts "Seek -6"
  f.seek -6, IO::SEEK_CUR
  puts f.pos.to_s + " : " + f.readline

  puts "Seek -10 from END"
  f.seek -10, IO::SEEK_END
  puts f.pos.to_s + " : " + f.readline
end