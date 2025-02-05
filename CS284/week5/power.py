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
	if b == 0:
		return 1
	if b == 1:
		return a
	e = b//2
	if (b%2 == 0):
		v = powerOptimized(a, e)
		v*=v
	else:
		v = powerOptimized(a, e)
		v = v * v * a
	return v


def main():
	base = int(input("Enter an integer greater than 0: "))
	exponent = int(input("Enter the power: "))
	answer = powerOptimized(base,exponent)
	if (answer == -1):
		print("0^0 is undefined")
	else: 
		print(f"{base} to the power of {exponent} is {answer}")


main()
