def fib ( n ):
	if (n == 0 or n == 1):
		return 0
	if (n == 2):
		return 1
	return fib(n - 1) + fib(n - 2)

def fib_memoization (n, table):
	if table[n] != -1:
		return table[n]
	
	ans = fib_memoization(n - 1, table) + fib_memoization(n - 2, table)
	table[n] = ans

	return ans

def fib_tabulation (n, table):
	i = 3
	while (i <= n):
		table[i] = table[i-1] + table[i-2]
		i+=1
	
	return table[n]
	

def main ():
	n = 24
	table = [-1] * (n + 1)
	table[1] = 0
	table[2] = 1
	# print (fib_memoization(n, table))
	print (fib_tabulation(n, table))
	
main()
