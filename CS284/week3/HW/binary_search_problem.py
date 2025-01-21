# Lian Zhu
# CS284 1/20/2025 Homework
# Implement a solution using the Binary Search algorithm to find the minimum value stored in the shifted array.

def binary_search(array):
    left = 0
    right = len(array) - 1
    while (left < right):
        if (array[left] < array[right]): # Already sorted, can just return the left
            return array[left]

        middle = (left + right)//2
        if (array[right] < array[middle]): # Right half is where the smallest integer is  
            left = middle + 1
        else:
            right = middle # Middle can = smallest integer

    return array[left]


def main():

    test_cases = [[5, 6, 7, 8, 9, 10, 1, 2, 3, 4],
            [0, 1, 2, 4, 5, 6, 7],
            [4, 5, 6, 7, 0, 1, 2],
            [30, 40, 50, 66, 78, 11, 24],
            [6, 7, 1, 2, 3, 4, 5],
            [-3, -2, -1, 0, 1, 2],
            [2, 3, 4, 5, 6, 7, 1],
            [-5000, -4000, -3000, -2000, -1000, 0, 1000, 2000, 3000, 4000, 5000]]
    for array in test_cases:
        print(binary_search(array))
        # Answers:
        # 1, 0, 0, 11, 1, -3, 1, -5000

main()
    
