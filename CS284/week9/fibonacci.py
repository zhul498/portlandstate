def fib ( n ):
	if (n == 0 or n == 1):
		return 0
	if (n == 2):
		return 1
	return fib(n - 1) + fib(n - 2)



def fib_memoization (n, table):
	if n <= 1:
		return n
	if table[n] != -1:
		return table[n]
	
	ans = fib_memoization(n - 1, table) + fib_memoization(n - 2, table)
	table[n] = ans

	return ans
	

def main ():
	n = 90
	table = [-1] * (n + 1)
	print (fib_memoization(n, table))

main()
