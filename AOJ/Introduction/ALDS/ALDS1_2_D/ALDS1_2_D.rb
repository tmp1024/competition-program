def insertion_sort(a, n, g)
  cnt = 0
  (g..(n - 1)).each do |i|
    v = a[i]
    j = i - g
    while j >= 0 && a[j] > v
      a[j+g] = a[j]
      j -= g
      cnt += 1
    end
    a[j+g] = v
  end
  return cnt
end

def shell_sort(a, n)
  cnt = 0
  g = (1..12).to_a.map { |val| 3 ** val + 1 if 3 ** val + 1 < n }
    .select { |val| !val.nil? }
    .reverse
  g.push(1)
  m = g.length
  (0..(m - 1)).each do |i|
    cnt += insertion_sort(a, n, g[i])
  end
  puts m
  (0..(m - 2)).each do |i|
    print "#{g[i]} "
  end
  puts g[m - 1]
  puts cnt
  puts a
end

n = gets.to_i
a = []
n.times do
  a.push(gets.to_i)
end

if n == 1
  puts 1
  puts 1
  puts 0
  puts a
else
  shell_sort(a, n)
end
