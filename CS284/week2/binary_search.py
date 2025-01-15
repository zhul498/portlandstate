# Binary search implementationm

def binary_search(array, to_find, length):
	left = 0
	right = length - 1
	middle = (left + right)//2
	while (left < right):
		if array[middle] == to_find:
			return middle
		elif to_find > array[middle]:
			left = middle + 1
			middle = (left + right)//2
		else:
			right = middle - 1
			middle = (left + right)//2
	return -1

def main():
	array = [1,2,3,4,5,6,7,8,9,10]
	length = len(array)
	to_find = int(input("Enter a number 1-10: "))
	found = binary_search(array, to_find, length)
	print(f"{to_find} lives at index {found}")

main()
