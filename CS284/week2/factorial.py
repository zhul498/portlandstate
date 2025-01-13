# Factorial function
def factorial(n) -> int:
	if (n == 0 or n == 1):
		return 1;
	else:
		previous = factorial(n - 1)
		current = n * previous
	return current

def main(): 
	x = int(input("Enter n: "))
	answer = factorial(x)
	print(f"The factorial of {x} is: {answer}")

main()
