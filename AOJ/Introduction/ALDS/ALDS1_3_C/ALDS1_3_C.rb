n = gets.to_i

list = []

n.times do
  input = gets.split
  if input[0] == 'insert'
    list.unshift(input[1].to_i)
  elsif input[0] == 'delete'
    index = list.find_index(input[1].to_i)
    list.delete_at(index) unless index.nil?
  elsif input[0] == 'deleteFirst'
    list.shift
  elsif input[0] == 'deleteLast'
    list.pop
  end
end

if list.length == 1
  puts list
else
  (0...(list.length - 1)).each do |i|
    print "#{list[i]} "
  end
  puts list[list.length - 1]
end
