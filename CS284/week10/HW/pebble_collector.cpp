#include <bits/stdc++.h>
using namespace std;
// Prototypes
void makeField (vector<vector<int>> & field, int rows, int cols);
void displayField (vector<vector<int>> field);
int naive (vector<vector<int>> field);
int memoization (vector<vector<int>> field, vector<vector<int>> & dp, int r, int c);
vector<vector<int>> generateDp (int r, int c);
int tabulation (vector<vector<int>> field, vector<vector<int>> & dp, int r, int c);


// Generates a field, with r rows and c cols
void makeField (vector<vector<int>> & field, int r, int c)
{
	int rows = 0;
	while (rows < r)
	{
		vector<int> temp;
		int cols = 0;
		while (cols < c)
		{
			int pebble = rand() % 2;
			temp.push_back(pebble);
			++cols;
		}
		field.push_back(temp);
		++rows;
	}
}

// Displays the field
void displayField (vector<vector<int>> field)
{
	int n = field.size();
	int m = field[0].size();
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cout << field[i][j] << " ";
		}
		cout << endl;
	}
}


// Recursive -- naive approach
int naive (vector<vector<int>> field, int r, int c)
{
	if (r < 0 || c < 0)
		return 0;
	return field[r][c] + max(naive(field, r-1, c), naive(field, r, c-1));

}

// Generate a field of -1 for dp
vector<vector<int>> generateDp (int r, int c)
{
	vector<vector<int>> generated;
	int rows = 0;
	while (rows < r)
	{
		vector<int> temp;
		int cols = 0;
		while (cols < c)
		{
			temp.push_back(-1);
			++cols;
		}
		generated.push_back(temp);
		++rows;
	}
	return generated;
}

// Memoization
int memoization (vector<vector<int>> field, vector<vector<int>> & dp, int r, int c)
{
	if (r < 0 || c < 0) 
		return 0;
	// Base case
	if (r == 0 && c == 0)
		return field[0][0];
	
	if (dp[r][c] != -1)
		return dp[r][c];

	int left = memoization(field, dp, r, c - 1);
	int up = memoization(field, dp, r - 1, c);

	dp[r][c] = field[r][c] + max(left, up);
	
	return dp[r][c];


}

// Tabulation
int tabulation (vector<vector<int>> field, vector<vector<int>> & dp, int r, int c)
{
	if (r < 0 || c < 0)
		return 0;
}


int main ( )
{
	vector<vector<int>> field;
	int rows = 0;
	int cols = 0;
	cout << "Enter num rows: ";
	cin >> rows; cin.ignore(100, '\n');
	cout << "Enter num cols: ";
	cin >> cols; cin.ignore(100, '\n');

	makeField(field, rows, cols);
	displayField(field);

	int pebblesOne = naive(field, rows - 1, cols - 1);
	cout << "Naive: " << pebblesOne << endl;

	vector<vector<int>> dp = generateDp(rows, cols);
	displayField(dp);

	int pebblesTwo = memoization(field, dp, rows - 1, cols - 1);
	cout << "Memoization: " << pebblesTwo << endl;
	displayField(dp);

	return 0;

}
