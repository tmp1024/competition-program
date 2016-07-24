def bubbleSort(n, a)
  change = 0
  flag = true
  while flag
    flag = false
    (1..(n-1)).reverse_each do |j|
      if a[j] < a[j-1]
        change += 1
        a[j], a[j - 1] = a[j - 1], a[j]
        flag = true
      end
    end
  end
  return change
end

n = gets.to_i
a = gets.split().map(&:to_i)

change = bubbleSort(n, a)

(0..(n - 2)).each do |i|
  print "#{a[i]} "
end
puts a[n - 1]
puts change
