def bubble_sort(c, n)
  (0..(n - 1)).each do |i|
    ((i + 1)..(n - 1)).reverse_each do |j|
      c[j], c[j - 1] = c[j - 1], c[j] if c[j][1].to_i < c[j - 1][1].to_i
    end
  end
end

def selection_sort(c, n)
  (0..(n - 1)).each do |i|
    minj = i
    (i..(n - 1)).each do |j|
      minj = j if c[j][1].to_i < c[minj][1].to_i
    end
    c[minj], c[i] = c[i], c[minj] unless c[minj] == c[i]
  end
end

n = gets.to_i
orig_c = gets.split

bubble_c = orig_c.dup
bubble_sort(bubble_c, n)
(0..(n - 2)).each do |i|
  print "#{bubble_c[i]} "
end
puts bubble_c[n - 1]
puts "Stable"

selection_c = orig_c.dup
selection_sort(selection_c, n)
(0..(n - 2)).each do |i|
  print "#{selection_c[i]} "
end
puts selection_c[n - 1]
flag = true
bubble_c.each_with_index do |val, i|
  flag = false unless val == selection_c[i]
end
puts "Stable" if flag
puts "Not stable" unless flag
