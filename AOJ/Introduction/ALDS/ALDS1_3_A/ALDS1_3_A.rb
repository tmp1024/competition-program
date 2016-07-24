str = gets.split

st = []
for i in str do
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
    st.push i.to_i
  end
end

puts st[0]
