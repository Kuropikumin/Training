fiber = Fiber.new { |input|
  puts input
  into_fiber = Fiber.yield( 'goodbye' )
  puts into_fiber
  'return fiber'
}

puts fiber.resume( 'input first' )
puts fiber.resume( 'input second' )
puts fiber.resume( 'input third' )