loop do
  input = gets.to_s
  break if input.empty?
  year, month, day = input.split.map(&:to_i)
  ad = sprintf("%d%02d%02d", year, month, day)
  ad = ad.to_i

  if ad <= 18680907
    puts 'pre-meiji'
  elsif ad <= 19120729
    puts "meiji #{year - 1867} #{month} #{day}"
  elsif ad <= 19261224
    puts "taisho #{year - 1911} #{month} #{day}"
  elsif ad <= 19890107
    puts "showa #{year - 1925} #{month} #{day}"
  else
    puts "heisei #{year - 1988} #{month} #{day}"
  end
end
