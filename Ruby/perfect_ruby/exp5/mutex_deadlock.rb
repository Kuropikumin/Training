m1, m2 = Mutex.new, Mutex.new
t1 = Thread.fork {
  m1.lock
  sleep 1
  m2.lock
}

t2 = Thread.fork {
  m2.lock
  sleep 1
  m1.lock
}

t1.join
t2.join