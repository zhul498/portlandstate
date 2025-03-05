#include <bits/stdc++.h>
using namespace std;


// Function that returns a pair of 2 halves of an array
pair<vector<int>> separate (vector<int> array)
{
	pair<vector<int>> separated;


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
	return 0;
}
