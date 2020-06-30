#include <vector>
#include <limits>

int get_change(int m) {
	
	std::vector<int> minNumCoins(m+1);
	std::vector<int> coins{ 1,3,4 }; // coins available for change

	for (int i = 1; i <= m; i++)
	{
		minNumCoins[i] = std::numeric_limits<int>::max();
		for (size_t j = 0; j < coins.size(); j++)
		{
			if (i >= coins[j])
			{
				int NumCoins = minNumCoins[i - coins[j]] + 1;
				if (NumCoins < minNumCoins[i])
				{
					minNumCoins[i] = NumCoins;
				}
			}
		}
	}

	return minNumCoins[m];
}