CONSTANT_FOO = 'CONSTANT_FOO is constant'
puts CONSTANT_FOO

CONSTANT_FOO = 'bar'  # Warning: already initialized constant CONSTANT_FOO
puts CONSTANT_FOO

def mymethod
  CONSTANT_BAR = 'bar' # Error: dynamic constant assignment
  puts CONSTANT_BAR
end