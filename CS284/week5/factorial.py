def factorial(n):
	if n == 1 or n == 0:
		return 1
	return n * factorial(n-1)

def main():
	userInput = int(input("Enter a number: "))
	answer = factorial(userInput)
	print(f"The factorial of {userInput} is {answer}")

main()
