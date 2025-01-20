File.open 'text/foo.txt', File::WRONLY | File::CREAT do |f|
  f.puts 'puts'
  f.puts

  f.print 'print'

  f.printf "%03d", 7

  f.putc 97
end