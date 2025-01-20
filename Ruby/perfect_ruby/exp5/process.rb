hoge = 10

pid = Process.fork

if pid
    fuga = 20
    puts "forked: #{$$}"
    puts "parent process: #{hoge}"
    hoge += 8
else
    puts 'From child process'
    puts "child process: #{hoge}"
    hoge += 9
    puts "child fuga is #{fuga}"
end

puts "End hoge is #{hoge}"
puts "End fuga is #{fuga}"
