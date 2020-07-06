#include <algorithm>
#include <vector>

using std::vector;

int lcs2(vector<int>& a, vector<int>& b) {
	
	const int row = a.size();
	const int column = b.size();
	int D[100][100] = { 0 }; // create 2d array of max size

	// build 2D array of subsequence matches

	for (int j = 1; j <= column; j++)
	{
		for (int i = 1; i <= row; i++)
		{
			int rem_a = D[i-1][j];
			int rem_b = D[i][j - 1];
			int match = D[i - 1][j - 1];

			if (a[i - 1] == b[j - 1])
			{
				D[i][j] = match + 1;
			}
			else
			{
				D[i][j] = std::max(rem_a, rem_b);
			}

		}
	}

	return D[row][column];
}


