# Binary search implementationm

def binary_search(array, to_find, length):
	left = 0
	right = length
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

def binary_search_recursion(array, to_find, left, right):
	middle = (left + right)//2
	while (left < right):
		if array[middle] == to_find:
			return middle
		elif to_find > array[middle]:
			return binary_search_recursion(array, to_find, left + 1, right)
		else:
			return binary_search_recursion(array, to_find, left, right - 1)
	return -1

def main():
	array = [1,2,3,4,5,6,7,8,9,10]
	length = len(array)
	to_find = int(input("Enter a number 1-10: "))
	found = binary_search(array, to_find, length)
	left = 0
	right = length
	found_recursive = binary_search_recursion(array, to_find, left, right)
	print(f"{to_find} lives at index {found}")
	print(f"Recursively, {to_find} lives at index {found_recursive}")

main()
