require 'open-uri'
require 'uri'
require 'net/https'

print "donwload URL > "
url = URI.parse(gets.chomp)

print "download directory > "
download_dir = '/mnt/d/Users/kuropikumin/Desktop/test/' + gets.chomp
Dir.mkdir(download_dir) if !Dir.exist?(download_dir)

print "start page num > "
start_page_num = gets.to_i

print "end page num > "
end_page_num = gets.to_i

http = Net::HTTP.new(url.host, url.port)
if url.port == 443
  http.use_ssl = true
  http.ssl_timeout = 600
end

http.start do |h|
  for i in start_page_num..end_page_num do
    file = sprintf("#{download_dir}/%04d.jpg", i)
    file_name = sprintf("%04d.jpg", i)
    #puts url.request_uri + file_name
    #response = h.get(url + file_name)
    puts url.request_uri + "#{i}.jpg"
    response = h.get(url + "#{i}.jpg")
    open(file, 'w') do |pass|
      pass.write(response.body)
    end
  end
end
