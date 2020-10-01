def sweet
  'solt'
end

def Hello
  p 'Hello'
end

sweet = 'sweet'

p sweet
p sweet()

# p Hello # NameErrorが発生（頭文字が大文字の場合、クラス名であると判断される。頭が大文字の場合、以下のようにする）
self.Hello
Hello()
