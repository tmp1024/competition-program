n, q = gets.split.map(&:to_i)

sche = []

n.times do
  process, time = gets.split
  sche.push([process, time.to_i])
end

sum_time = 0

until sche.empty?
  h = sche.shift
  process = h[0]
  time = h[1]
  if time <= q
    sum_time += time
    puts "#{process} #{sum_time}"
  else
    sum_time += q
    time -= q
    sche.push([process, time])
  end
end
