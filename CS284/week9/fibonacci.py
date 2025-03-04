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

def nCk_memo(n, k, table):
	if table[n][k] != -1:
		return table[n][k]
	ans = nCk_memo(n-1, k-1, table) + nCk_memo(n-1, k, table)
	table[n][k] = ans

	return ans


def main ():
	#n = 990
	#table = [-1] * (n + 1)
	#table[1] = 0
	#table[2] = 1
	#print (fib_memoization(n, table))
	n = 6
	k = 3
	table = [[-1 for j in range(n)] for i in range(k)]
	print(nCk_memo(n, k, table))

main()
