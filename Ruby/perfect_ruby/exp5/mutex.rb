def countup
  File.open 'text/counter.txt', File::RDWR | File::CREAT do |f|
    last_count = f.read.to_i

    f.rewind
    f.write last_count + 1
  end
end

mutex = Mutex.new

10.times.map {
  Thread.fork {
    sleep( 1 )
    mutex.synchronize{ countup }
  }
}.map( &:join )

puts File.read( 'text/counter.txt' ).to_i