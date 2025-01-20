files = %w( .screenrc .bashrc .vimrc )
threads = files.map { |file|
  Thread.fork {
    puts "#{file} start"
    p Thread.main
    p Thread.list
    num = File.readlines( "/home/kuropikumin/" + file ).length

    # if( file == ".bashrc" ) then sleep( 1 ) end
    # sleep( 1 )
    p "#{file}: #{num}"
  }
}

threads.map( &:value )