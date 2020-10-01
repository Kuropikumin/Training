count = 0
catch :triple_loop do
  loop do
    p 'one'
    loop do
      p 'two'
      loop do
        p 'three'
        count += 1
        if(count > 5) then throw :triple_loop end
      end
    end
  end
end

