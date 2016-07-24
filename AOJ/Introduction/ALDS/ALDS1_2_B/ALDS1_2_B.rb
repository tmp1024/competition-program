def selectionSort(a, n)
  change = 0
  for i in 0..(n - 1)
    minj = i
    for j in i..(n - 1)
      if a[j] < a[minj]
        minj = j
      end
    end
    unless minj == i
      a[minj], a[i] = a[i], a[minj]
      change += 1
    end
  end
  change
end

n = gets.to_i
a = gets.split().map(&:to_i)

change = selectionSort(a, n)

(0..(n - 2)).each do |i|
  print "#{a[i]} "
end
puts a[n - 1]
puts change
