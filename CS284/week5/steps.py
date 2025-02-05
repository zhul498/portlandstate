def steps(n):
	if (n == 0):
		return 0
	if (n == 1 or n == 2):
		return n
	return steps(n - 1) + steps(n - 2)

def main():
	n = int(input("Enter # of stairs: "))
	ans = steps(n)
	print(ans)

main()
