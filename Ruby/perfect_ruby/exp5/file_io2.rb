puts "read > "
File.open "text/test.txt" do |file|
  puts file.read
  puts "hoge"
end

puts "\ngets > "
File.open "test.txt" do |file|
  while line = file.gets
    puts line
    puts "hoge"
  end
end

puts "\neach_line > "
File.open "test.txt" do |file|
  file.each_line do |line|
    puts line
    puts "hoge"
  end
end
