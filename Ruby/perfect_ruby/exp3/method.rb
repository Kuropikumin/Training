def sweet
  'solt'
end

def Hello
  p 'Hello'
end

def hello
  p 'hello'
end

sweet = 'sweet'

p sweet
p sweet()

# p Hello # uninitialized constant Hello (NameError)
p Hello()

p hello
self.hello
hello()
hello