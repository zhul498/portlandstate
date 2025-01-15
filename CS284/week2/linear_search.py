# Linear Search - over an array of integers

def linear_search(array, target):
	index = 0
	length = len(array)
	while (index < length):
		if array[index] == target:
			return index
		index+=1
	return -1

def main():
	array = [5,1,10,12,14,2]
	k = 2
	result = linear_search(array, k)
	print(result)

main()
