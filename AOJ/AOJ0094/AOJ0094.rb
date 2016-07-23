input = gets
a, b = input.split().map(&:to_i)

puts "%.6f" % (a * b / 3.305785)
