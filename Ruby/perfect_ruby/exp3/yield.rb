def my_sample
  puts 'before yield!'
  puts yield # if block_given?
  puts 'after yield!'
end

my_sample do
  puts 'yield!!!'
  5523
end

# my_sample # LocalJumpError(yield$B$G<B9T$9$k$?$a$N%V%m%C%/$rEO$7$F$$$J$$$?$a(B) 
          # -> block_given?$B$r;H$C$F(Bblock$B$rEO$7$?$+3NG'$9$k$H!"(BError$B$rHr$1$i$l$k(B

