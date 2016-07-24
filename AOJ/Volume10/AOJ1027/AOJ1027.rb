while k = gets.to_i
  break if k == 0
  ans = 0
  gets.chomp.split(" ").map(&:to_i).each do |val|
    ans += val
  end
  puts ans / (k - 1)
end
