rhom = []
$mlen = 0
$ans = 0
$dp = Array.new(100) { Array.new(100, 0) }

def dfs(rhom, depth, i, sum)
  if depth == rhom.length - 1
    return $ans = [$ans, sum+rhom[depth][0]].max
  end
  return if $dp[depth][i] > sum
  $dp[depth][i] = sum

  if depth < $mlen - 1
    dfs(rhom, depth+1, i, sum+rhom[depth][i])
    dfs(rhom, depth+1, i+1, sum+rhom[depth][i])
  else
    dfs(rhom, depth+1, i, sum+rhom[depth][i]) unless i == rhom[depth].length - 1
    dfs(rhom, depth+1, i-1, sum+rhom[depth][i]) unless i == 0
  end
  return
end

loop do
  input = gets.to_s
  break if input.empty?
  input = input.split(",").map(&:to_i)
  rhom.push(input)
  $mlen = [$mlen, input.length].max
end
dfs(rhom, 0, 0, 0)
puts $ans
