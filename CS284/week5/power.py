def power(a, b):
	if a == 0 and b == 0:
		return -1
	if b == 0:
		return 1
	if b == 1:
		return a
	return a * power(a, b-1)


def main():
	base = int(input("Enter an integer greater than 0: "))
	exponent = int(input("Enter the power: "))
	answer = power(base,exponent)
	print(f"{base} to the power of {exponent} is {answer}")


main()
