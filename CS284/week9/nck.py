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

def f_tabulation(n, k, table):
	i = 3
	j = 2
	while (i <= n):
		while (j <= k):
			table[i][j] = (table[i-1][j-1] + table[i-1][j])
			j+=1
		i+=1
	
	return table[n][k]
		
	

def main ( ):
	n = 6
	k = 3

	# Build table initialized with -1 with n rows and k cols
	table = [[-1] * (k+1) for _ in range(n+1)]
	# base cases for tabulation
	table[2][2] = 1
	table[2][1] = 2
	
	answer = f_tabulation(n, k, table)
	for rows in table:
		print(rows)

main()
