CONSTANT_FOO = 'CONSTANT_FOO is constant'
puts CONSTANT_FOO

CONSTANT_FOO = 'bar' # warning$BH/@8(B($BDj?t$K:FBeF~$r$7$h$&$H$7$F$$$k$?$a(B)
puts CONSTANT_FOO    # $BDj?t$K:FBeF~$r$9$k>l9g!"(Bwarning$B$OH/@8$9$k$,%(%i!<$K$O$J$i$J$$(B

def mymethod
  CONSTANT_BAR = 'bar' # dynamic constant assigmentError$BH/@8!J%a%=%C%IFb$G$ODj?t$ODj5A$G$-$J$$$?$a!K(B
  puts CONSTANT_BAR
end
