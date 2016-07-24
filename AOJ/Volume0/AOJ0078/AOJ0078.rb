while n = gets.to_i
  break if n == 0
  square = Array.new(n){ Array.new(n, 0) }
  y = n / 2 + 1
  x = n / 2
  square[y][x] = 1
  (2..(n*n)).each do |val|
    y += 1
    x += 1
    y = 0 if y >= n
    x = 0 if x >= n
    if square[y][x] > 0
      y += 1
      x -= 1
      y = 0 if y >= n
      x = n - 1 if x < 0
    end
    square[y][x] = val
  end
  square.each do |arr|
    arr.each do |val|
      print "%4d" % val
    end
    print "\n"
  end
end
