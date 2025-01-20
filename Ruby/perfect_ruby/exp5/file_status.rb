f = File.open( 'text/foo.txt', &:stat )
puts "以下のメソッドは通常のFile.openで利用可能"
puts "atime（最終アクセス日時）: " + f.atime.to_s
puts "ctime（最終状態変更日時）: " + f.ctime.to_s
puts "mtime（最終更新日時）: "     + f.mtime.to_s
puts "size（ファイルサイズ）: "   + f.size.to_s

puts "\n以下のメソッドは、File.open時に&:statを宣言することで利用可能"
puts "ftype（ファイルタイプ）: "                + f.ftype.to_s
puts "file?（ファイルかどうか）: "              + f.file?.to_s
puts "directory?（ディレクトリかどうか）: "     + f.directory?.to_s
puts "symlink?（シンボリックリンクかどうか）: " + f.symlink?.to_s
puts "pipe?（パイプかどうか）: "                + f.pipe?.to_s
puts "socket?（ソケットかどうか）: "            + f.socket?.to_s
puts "writable?（書き込み可能か）: "            + f.writable?.to_s
puts "readable?（読み込み可能か）: "            + f.writable?.to_s
puts "executable?（実行可能か）: "              + f.writable?.to_s
puts "owned?（オーナーか）: "                   + f.owned?.to_s
puts "gid（ファイルオーナーのgid）: "           + f.gid.to_s
puts "uid（ファイルオーナーのuid）: "           + f.uid.to_s
puts "ino（ファイルのinode）: "                 + f.ino.to_s
puts "dev（ファイルのデバイス番号）: "          + f.dev.to_s