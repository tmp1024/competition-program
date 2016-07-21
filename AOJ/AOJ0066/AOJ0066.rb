color = ["o", "x"]

while mass = gets
  flag = ""
  (0..1).each do |player|
    (0..2).each do |val|
      val = val * 3
      if mass[val] == color[player] && mass[val] == mass[val+1] && mass[val+1] == mass[val+2]
        flag = color[player]
      end
    end
    (0..2).each do |val|
      if mass[val] == color[player] && mass[val] == mass[val+3] && mass[val+3] == mass[val+6]
        flag = color[player]
      end
    end
    if mass[0] == color[player] && mass[0] == mass[4] && mass[4] == mass[8]
      flag = color[player]
    end
    if mass[2] == color[player] && mass[2] == mass[4] && mass[4] == mass[6]
      flag = color[player]
    end
  end
  if flag == "o" || flag == "x"
    puts flag
  else
    puts "d"
  end
end
