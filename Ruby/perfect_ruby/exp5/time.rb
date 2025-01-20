p "TIME > " + Time.now.to_s

time = Time.new

p "ZONE > " + time.zone
p "UTC TIME > " + time.getutc.to_s

p "year > " + time.year.to_s
p "month > " + time.month.to_s
p "day > " + time.day.to_s
p "hour > " + time.hour.to_s
p "min > " + time.min.to_s
p "sec > " + time.sec.to_s
p "nsec > " + time.nsec.to_s

p "wday > " + time.wday.to_s
p "yday > " + time.yday.to_s
