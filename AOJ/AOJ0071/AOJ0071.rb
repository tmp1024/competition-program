$dx = [-3, -2, -1, 1, 2, 3, 0, 0, 0, 0, 0, 0]
$dy = [0, 0, 0, 0, 0, 0, -3, -2, -1, 1, 2, 3]

def chain(field, ans, x, y)
  12.times do |index|
    sx = x + $dx[index]
    sy = y + $dy[index]
    if 0 <= sx && sx < 8 && 0 <= sy && sy < 8
      if field[sy][sx] == '1'
        field[sy][sx] = '0'
        chain(field, ans, sx, sy)
      end
      ans[sy][sx] = '0'
    end
  end
end

n = gets.to_i
n.times do |num|
  field = []
  str = gets
  8.times do
    str = gets.to_s
    field.push(str)
  end
  ans = field.map(&:dup)
  x = gets.to_i
  y = gets.to_i
  ans[y - 1][x - 1] = '0'
  chain(field, ans, x-1, y-1)
  puts "Data #{num+1}:"
  puts ans
end
