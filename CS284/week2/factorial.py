# Factorial function
def factorial(n) -> int:
	if (n < 0):
		return -1
	if (n == 0 or n == 1):
		return 1
	return n * factorial(n - 1)

def main(): 
	x = int(input("Enter n: "))
	answer = factorial(x)
	if (answer == -1):
		print(f"We cannot calculate the factorial of negative numbers")
	else:
		print(f"The factorial of {x} is: {answer}")

main()
