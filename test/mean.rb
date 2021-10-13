#!/usr/bin/ruby

if ARGV.length != 2
	puts "mean.rb: wrong number of arguments, requires 2 integers \n\t- usage: mean.rb [number of tests] [number of values]"
	exit 1
end

working = ['|', '/', '-', '\\', '|', '/', '-', '\\']

mean = 0;
min = -1;
max = -1;

for i in 1..ARGV[0].to_i
	print "running test #{i}/#{ARGV[0].to_i} ... #{working[i % working.length]}\r"
	$stdout.flush
	random_values = (-9999..9999).to_a.sample(ARGV[1].to_i).join(' ')
	moves = `./push_swap #{random_values} | wc -l`.to_i
	if (moves > max)
		max = moves
	end
	if (moves < min || min == -1)
		min = moves
	end
	mean += moves;
end

mean = mean / ARGV[0].to_i

puts "\nmean = #{mean} average moves for #{ARGV[0].to_i} tests of #{ARGV[1].to_i} values"
puts "min = #{min.to_i} moves"
puts "max = #{max.to_i} moves"
