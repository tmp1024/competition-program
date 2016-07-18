loop do
  q = gets.to_i
  break if q == -1

  x = q.to_f / 2
  loop do
    break if (x ** 3 - q).abs < 0.00001 * q
    x = x - ((x ** 3 - q) / (3 * (x ** 2)))
  end
  puts x
end
