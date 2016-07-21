loop do
  input = gets.chomp
  n, m = input.split(" ").map(&:to_i)
  break if n == 0 && m == 0
  circ = (1..n).to_a
  ex = n - 1
  until circ.length == 1
    ex += m
    ex -= n while ex >= n
    circ.delete_at(ex)
    n -= 1
    ex -= 1
    ex = n - 1 if ex == -1
  end
  puts circ[0]
end
