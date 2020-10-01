def my_exception_check(error_name, error_message)
  raise error_name, error_message
end

begin
  my_exception_check( LoadError, '0で割り算が実施されました' )
rescue ZeroDivisionError => e
  puts e.class
  puts e.message
  puts e.backtrace
rescue StandardError => e
  puts e.class
  puts e.message
  puts e.backtrace
rescue Exception => e
  puts e.class
  puts '想定外のエラーが起きました'
  puts e.backtrace
ensure
  puts 'ここは ensure 部分です'
end
