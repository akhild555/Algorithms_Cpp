#include <vector>

int optimal_weight(int W, const std::vector<int>& w) {
    
    const int row = w.size();
    const int column = W;
    int D[100][100] = { 0 }; 

	for (int i = 1; i <= row; i++)
	{
		for (int j = 1; j <= column; j++)
		{
            D[j][i] = D[j][i - 1];
            if (w[i-1] <= j) // i-1 since indexing from 1 in for loop
            {
                int val = D[j - w[i-1]][i - 1] + w[i-1];
                if (D[j][i] < val)
                {
                    D[j][i] = val;
                }
            }
		}
	}
    return D[W][row];
}