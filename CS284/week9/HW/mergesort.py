# Takes an array and separates it, returns the 2 separate arrays
def separate (array):
	length = len(array)
	middle = length//2
	
	left_array = array[:middle]
	right_array = array[middle:]

	return left_array, right_array
	


# Takes 2 arrays as input, returns 1 merged array
def merge (array1, array2):
	left_size = len(array1)
	right_size = len(array2)
	merged = []
	lp = 0
	rp = 0
	# Compare and append to merge
	while (lp < left_size and rp < right_size):
		if (array1[lp] < array2[rp]):
			merged.append(array1[lp])
			lp+=1
		else:
			merged.append(array2[rp])
			rp+=1
	
	# Check to see which one has remaining elements, and append all of it to merge
	if (lp < left_size):
		merged.extend(array1[lp:])
	if (rp < right_size):
		merged.extend(array2[rp:])

	return merged

# Takes an array, recursively separates it until the length is 1 (base case) and then merge it
def merge_sort (array):
	if (len(array) <= 1):
		return array

	left, right = separate(array)

	left_sorted = merge_sort(left)
	right_sorted = merge_sort(right)

	return merge(left_sorted, right_sorted)

def main ( ):

	data = []
	item = int(input())
	while (item != -1):
		data.append(item)
		item = int(input())
	
	merged_array = merge_sort(data)
	print(merged_array)
	
main()

# Get middle of array, split array into both left and right half continuously until there is 1. And then 
# Merge together with 2 pointers to determine which element goes which way
