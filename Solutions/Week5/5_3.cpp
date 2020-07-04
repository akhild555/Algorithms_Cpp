#include <string>
#include <algorithm>

using std::string;

int edit_distance(const string& str1, const string& str2) {
	
	const int row = str1.length();
	const int column = str2.length();
	int D[100][100] = { 0 }; // create 2d array of max size

	// fill first row and column with 0 : length of string - 1

	for (int i = 1; i <= row; i++)
	{
		D[i][0] = i;
	}

	for (int j = 1; j <= column; j++)
	{
		D[0][j] = j;
	}


	// build 2D array of editing distances

	for (int j = 1; j <= column; j++)
	{
		for (int i = 1; i <= row; i++)
		{
			int insertion = D[i][j - 1] + 1;
			int deletion = D[i - 1][j] + 1;
			int match = D[i - 1][j - 1];
			int mismatch = D[i - 1][j - 1] + 1;
			if (str1[i-1] == str2[j-1])
			{
				D[i][j] = std::min(insertion, std::min(deletion, match));
			}
			else
			{
				D[i][j] = std::min(insertion, std::min(deletion, mismatch));
			}

		}
	}

	return D[row][column]; // entry in last row, last column is the editing distance for entire words
}