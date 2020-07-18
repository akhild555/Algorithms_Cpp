#include <vector>
#include <numeric>

int partition3(std::vector<int>& A) {
	
    const int row = A.size();
    const int column = std::accumulate(A.begin(), A.end(),0);
    int D[110][110] = { 0 };

    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= column; j++)
        {
            D[j][i] = D[j][i - 1];
            if (A[i - 1] <= j) // i-1 since indexing from 1 in for loop
            {
                int val = D[j - A[i - 1]][i - 1] + A[i - 1];
                if (D[j][i] < val)
                {
                    D[j][i] = val;
                }
            }
        }
    }
	return D[column][row];
}