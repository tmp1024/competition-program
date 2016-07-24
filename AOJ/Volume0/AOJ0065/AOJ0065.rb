lamo = Hash.new
thmo = Hash.new

while input = gets do
  input = input.chomp.to_s
  break if input.empty?
  input = input.split(",").map(&:to_i)
  if lamo.has_key?(input[0])
    lamo[input[0]] = lamo[input[0]] + 1
  else
    lamo[input[0]] = 1
  end
end

while input = gets do
  input = input.chomp.split(",").map(&:to_i)
  if thmo.has_key?(input[0])
    thmo[input[0]] = thmo[input[0]] + 1
  else
    thmo[input[0]] = 1
  end
end

lamo.select { |key, val|
  thmo.has_key?(key)
}
  .sort
  .each do |key, val|
  puts "#{key} #{lamo[key] + thmo[key]}"
end
