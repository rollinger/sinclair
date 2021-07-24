#
# Statistic library for Ruby
# Copyright 2008 Philipp Rollinger
#

# A Library for basic and advanced statistic computing based on vectors and matrices.


#
#BEGIN MODULE Stat
#
module Stat

# Gather statistics for vector
def Stat.summary(vector)
	#do density calc to dist Hash
	summary = Hash[:n, vector.length]
	#frequency table
	summary[:freq] = freq_table(vector)
	#calc min max
	summary[:min] = vector.min
	summary[:max] = vector.max
	#calc mean
	summary[:mean] = mean(vector)
	#calc modus
	summary[:modus] = modus(vector)
	#calc variation, variance, sd and skewness
	summary[:variation] = variation(vector)
	summary[:variance] = variance(vector)
	summary[:sd] = sd(vector)
	summary[:skewness] = skewness(vector)
	#return
	summary
end

def Stat.show_var(var)
	if var.kind_of? Array
		var = summary(var)
	end
	print ["--SUMMARY--\n","n:\t#{var["_pop"]}\n","mean:\t#{var["_mean"]}\n","modus:\t#{var["_modus"]}\n","SSx:\t#{var["_variation"]}\n","s2x:\t#{var["_variance"]}\n","sd:\t#{var["_sd"]}\n","skew:\t#{var["_skewness"]}\n"]
	stem(var)
end

# Returns a categorized vector
def Stat.recode_float(vector, resolution=[0.0..0.25,0.25..0.50,0.50..0.75,0.75..1.0])
  new_vector = []
  resolution.each do |r|
    vector.each do |v|
      if r === v
	new_vector.push( r.first )
      end
    end
  end
  return new_vector
end

def Stat.stem(vector, mode = 1)
	if vector.kind_of? Array
		vector = ratio_table(vector)#summary(vector)
	end
	stem = Array.new
	cumul = 0.0
	vector.each do |r|
		if r !~ /_\s*/
			ratio = r[1] #v/vector["_pop"].to_f
			cumul += r[1]
			num = (100*ratio).to_i
			ratio = format("%.5f",ratio)
			cumulative = format("%.5f",cumul)
			hist = "#{'O'*num}"
			stem.push([r[0],"\t[#{ratio}]\t[#{cumulative}]\t|#{hist}"])
		end
	end
	if mode == 1 #print to stdout
		s = stem.sort
		s.each {|x| puts x.to_s}
	end
	#return
	stem
end

# frequency table
def Stat.freq_table(vector)
	table = Hash.new
	vector.each do |real|
		if table.has_key?(real)
			table[real] += 1
		else
			table[real] = 1
		end
	end
	table = table.sort
	return table
end

# ratio table
def Stat.ratio_table(vector)
	n = vector.length
	table = freq_table(vector)
	table.each do |r|
		r[1] = r[1].to_f/n
	end
	#return
	table
end

def Stat.cumulative(freq)
	sum = 0
	cumul_tab = []
	freq.each do |val,real|
		sum += real
		cumul_tab.push([val,sum])
	end
	return cumul_tab
end

def Stat.percentile(p,vector)
	n = vector.length
	table = cumulative( freq_table(vector) )
	p = n * p
	table.each do |val,real|
		if real >= p
			return val
		end
	end
end

#span computation
def Stat.span(vector)
	#return
	span = [vector.min,vector.max]
end

# arithmetric mean computation
def Stat.mean(vector)
	mean = 0.00
	vector = vector.to_a
	vector.each do |real|
		mean += real
	end
	#return
	mean = mean / vector.length
end

# modus computation
def Stat.modus(vector)
	table = freq_table(vector)
	modus = [0,0]
	table.each do |x,n|
		if n > modus[1]
			modus = [x,n]
		end
	end
	#return
	modus[0]
end

# variation computation
def Stat.variation(vector)
	variation = 0.00
	vector = vector.to_a
	mean = mean(vector)
	vector.each do |real|
		variation += (real - mean)**2
	end
	#return
	variation
end

# variance computation
def Stat.variance(vector)
	#return
	vector = vector.to_a
	variance = variation(vector)/vector.length
end

# standard deviation computation
def Stat.sd(vector)
	#return
	return Math.sqrt( variance(vector) )
end

# Variationkoefficient computation
def Stat.vkoef(vector)
  return sd(vector) / mean(vector)
end

# Deviation computation
def Stat.deviance(vector)
  sum = total(vector)
  dev = 0.0
  vector.each do |v|
    dev += (-2 * Math.log( v/sum ) * v) rescue 0.0
  end
  return dev
end

# Relative Deviation computation
def Stat.relative_deviance(vector)
  sum = total(vector)
  dev = 0.0
  vector.each do |v|
    dev += (-2 * Math.log( v/sum ) * (v/sum) ) rescue 0.0
  end
  return dev
end

# Proportional Reduction of Error
def Stat.pre_lambda()

end

# Likelihood-Ratio-Index (coefficient of uncertainty)
def Stat.coefofuncertainty( vector_yx, vector_y )

end

def Stat.total(vector)
  sum = 0.0
  vector.each {|v| sum += v }
  return sum
end

# skewness computation
def Stat.skewness(vector)
	skewness = 0.00
	mean = mean(vector)
	vector.each do |real|
		skewness += (real - mean)**3
	end
	#return
	skewness = (skewness/vector.length)/(sd(vector)**3)
end

# covariance computation
def Stat.cov(vector1,vector2)
	# Arrays of same length?
	if vector1.length != vector2.length
		print "Vectors differ in length"
		exit
	end
	v1_mean = mean(vector1)
	v2_mean = mean(vector2)
	covariation = 0.00
	vector1.each_index do |x|
		covariation += (vector1[x]-v1_mean) * (vector2[x]-v2_mean)
	end
	#return
	covariation = covariation / vector1.length
end

# pearson correlation computation
def Stat.cor(vector1,vector2)
	# Arrays of same length?
	if vector1.length != vector2.length
		print "ERROR: Vectors differ in length"
		exit
	end
	#return
	correlation = cov(vector1,vector2) / (sd(vector1) * sd(vector2))
end

# pearson correlation computation with array truncation
def Stat.cor_trunc(vector1,vector2)
	#Same length?
	if vector1.length != vector2.length
		if vector1.length < vector2.length
			(vector2.length - vector1.length).times do
				vector2.pop
			end
		else
			(vector1.length - vector2.length).times do
				vector1.pop
			end
		end
	end
	#return
	correlation = cov(vector1,vector2) / (sd(vector1) * sd(vector2))
	puts correlation
end

# pearson correlation matrix
def Stat.cor_table(matrix, mode = 1)
	cor_table = Array.new
	#...?
	#return
	cor_table
end

# export array to cvs file
def Stat.csv_export(matrix, fname, join = ",")
	csv = File.open(fname,"w")
	for i in 0..matrix.length-1
		a = matrix.at(i).join(join)
		if a != nil
			csv.puts a
		end
	end
	csv.close
end

#
#END MODULE Stat
#
end 
