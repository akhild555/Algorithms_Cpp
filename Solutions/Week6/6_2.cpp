#include <vector>
#include <numeric>

int partition3(std::vector<int>& A) {
	
    const int row = A.size(); // # of items
    const int column = std::accumulate(A.begin(), A.end(),0) / 3; // total # columns = sum of values / number of people
    int D[150][150] = { 0 };

    // fill first column with 1's

    for (int i = 0; i < row; i++)
    {
        D[i][0] = 1;
    }

    // fill first row

    for (int i = 1; i <= column; i++)
    {
        if (i == A[0])
        {
            D[0][i] = 1;
        }
    }

    // fill remaining rows and columns

    for (int i = 1; i < row; i++)
    {
        for (int j = 1; j <= column; j++)
        {

            if (A[i] > j)
            {
                D[i][j] = D[i - 1][j];
            }
            if (j == A[i])
            {
                D[i][j] = 1;
            }
            if (D[i - 1][j] == 1)
            {
                D[i][j] = 1;
            }
            if (D[i - 1][j] == 0 && D[i - 1][j - A[i]] == 1)
            {
                D[i][j] = 1;
            }
        }
    }
	return D[row-1][column];
}