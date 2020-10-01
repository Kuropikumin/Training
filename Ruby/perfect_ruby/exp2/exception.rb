begin
  1/0
rescue ZeroDivisionError
  puts "割る数が 0 での除算が実施されました。\nプログラムを見直してください。"
end

puts 'ここは実行される'
