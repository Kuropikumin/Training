ENV['HOGE'] = 'huga'
system('echo $HOGE')

system( { 'HOGE' => 'piyo' }, 'echo $HOGE' )

pid = spawn( { 'HOGE' => 'piyopiyo' }, 'echo $HOGE' )

Process.waitpid pid
exec( { 'HOGE' => 'piyopiyopiyo' }, 'echo $HOGE' )
