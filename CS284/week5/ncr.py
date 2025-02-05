def nCr(n, r):
	# array n, number r	
	if (r == 1):
		return n
	if (r == n):
		return 1
	if (r == 0): 
		return 1
	return nCr(n-1, r-1) + nCr(n-1, r)




def main():
	n = int(input("Enter n: "))
	r = int(input("Enter r: "))
	ans = nCr(n, r)
	print(f"{n} choose {r} is {ans}")

main()
