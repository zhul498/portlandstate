# n Choose K -- naive approach
def nCk (n, k):
	if (k == n):
		return 1
	if (k == 1):
		return n
	return nCk(n-1,k-1) + nCk(n-1,k)

# nCk -- memoization, using a 2d array
def f(n, k, table):

	# base cases
	if (k == n):
		return 1
	if (k == 1):
		return n
	if (table[n][k] != -1):
		return table[n][k]
	
	answer = f(n-1, k-1, table) + f(n-1, k, table)
	table[n][k] = answer

	return answer

def main ( ):
	n = 100	
	k = 10

	# Build table initialized with -1 with n rows and k cols
	table = [[-1] * (k+1) for _ in range(n+1)]
	
	print(f(n, k, table))

main()
