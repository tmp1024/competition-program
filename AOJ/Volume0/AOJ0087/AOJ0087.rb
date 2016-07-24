loop do
  str = gets.to_s
  break if str.empty?
  str = str.split(" ")

  st = []
  str.each do |i|
    if i == '+'
      b = st.pop
      a = st.pop
      st.push(a + b)
    elsif i == '-'
      b = st.pop
      a = st.pop
      st.push(a - b)
    elsif i == '*'
      b = st.pop
      a = st.pop
      st.push(a * b)
    elsif i == '/'
      b = st.pop
      a = st.pop
      st.push(a / b)
    else
      st.push i.to_f
    end
  end
  puts "%6f" % st.pop
end
