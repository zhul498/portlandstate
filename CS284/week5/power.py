def power(a, b):
	if a == 0 and b == 0:
		return -1
	if b == 0:
		return 1
	return a * power(a, b-1)

# ?
def powerOptimized(a, b):
	if a == 0 and b == 0:
		return -1
	if b == 1:
		return a
	if b == 0:
		return 1
	e = b//2
	ans = powerOptimized(a, e)
	ans*=ans
	if (e%2 == 0):
		return ans
	else:
		return ans * a


def main():
	base = int(input("Enter an integer greater than 0: "))
	exponent = int(input("Enter the power: "))
	answer = powerOptimized(base,exponent)
	if (answer == -1):
		print("0^0 is undefined")
	else: 
		print(f"{base} to the power of {exponent} is {answer}")


main()
