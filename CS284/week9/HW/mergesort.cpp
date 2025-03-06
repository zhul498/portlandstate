#include <bits/stdc++.h>
using namespace std;
// Prototypes
vector<int> mergeSort (vector<int> array);
pair<vector<int>, vector<int>> separate (vector<int> array);
vector<int> merge (vector<int> array1, vector<int> array2);

// Merge sort function
vector<int> mergeSort (vector<int> array)
{
	if (array.size() <= 1) return array;

	pair<vector<int>, vector<int>> separatedArrays = separate(array);

	vector<int> leftSorted = mergeSort(separatedArrays.first);
	vector<int> rightSorted = mergeSort(separatedArrays.second);

	return merge(leftSorted, rightSorted);
}




// Function that returns a pair of 2 halves of an array
pair<vector<int>, vector<int>> separate (vector<int> array)
{
	pair<vector<int>, vector<int>> separated;
	int mid = array.size()/2;
	
	separated.first = vector<int>(array.begin(), array.begin() + mid);
	separated.second = vector<int>(array.begin() + mid, array.end());


	return separated;
}


// Merge, takes in 2 vectors and sorts them with 2 ptrs
vector<int> merge (vector<int> array1, vector<int> array2)
{
	int lp = 0;
	int rp = 0;
	int leftSize = array1.size();
	int rightSize = array2.size();
	vector<int> merged;


	// Merge
	while (lp < leftSize && rp < rightSize)
	{
		if (array1[lp] < array2[rp])
		{
			merged.push_back(array1[lp]);
			++lp;
		}
		else
		{
			merged.push_back(array2[rp]);
			++rp;
		}
	}
	
	// Push the rest 
	if (lp < leftSize)
	{
		merged.insert(merged.end(), array1.begin() + lp, array1.end());
	}
	if (rp < rightSize)
	{

		merged.insert(merged.end(), array1.begin() + rp, array1.end());
	}

	return merged;
}



int main ( )
{
	vector<int> array;
	int num = 0;
	do 
	{
		cout << "Enter a number (-1 TO CANCEL): ";
		cin >> num; cin.ignore(100, '\n');
		if (num != -1) array.push_back(num);
	} while (num != -1);

	vector<int> sorted = mergeSort(array);

	cout << "Sorted array: \n";
	for (const auto x : sorted)
	{
		cout << x << " ";	
	}	

	return 0;
}
