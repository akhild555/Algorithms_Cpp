#include <vector>
#include <algorithm>

using std::vector;

int lcs3(vector<int>& a, vector<int>& b, vector<int>& c) {
	
	const int row = a.size();
	const int column = b.size();
	const int height = c.size();
	int D[10][10][10] = { { {0} } }; // create 3D array 

	// build 3D array of subsequence matches

	for (int j = 1; j <= column; j++)
	{
		for (int i = 1; i <= row; i++)
		{

			for (int k = 1; k <= height; k++)
			{
				{
					int rem_a = D[i - 1][j][k];
					int rem_b = D[i][j - 1][k];
					int rem_c = D[i][j][k - 1];
					int match = D[i - 1][j - 1][k - 1];

					if (a[i - 1] == b[j - 1] && b[j - 1] == c[k - 1])
					{
						D[i][j][k] = match + 1;
					}
					else
					{
						D[i][j][k] = std::max(rem_a, std::max(rem_b, rem_c));
					}
				}
			}
		}
	}
	return D[row][column][height];
}