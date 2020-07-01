#include <vector>
#include <algorithm>
#include <map>
#include <iostream>

using std::vector;

vector<int> optimal_sequence(int n) {

	vector<int> minOp(n+1); // to keep track of fewest calculations for numbers up to n
	vector<int> nums{1,2,3}; // calculations: add 1, multiply by 2, multiply by 3
	int numOps = 0;
	std::map<int, vector<int>> cal; // dictionary to keep track of fewest calculations for numbers up to n
	cal[0] = vector<int>{ 1 };
	cal[1] = vector<int>{ 1 };

	for (int i = 2; i < n+1; i++)
	{
		int count = 0;
		minOp[i] = std::numeric_limits<int>::max();
		for (size_t j = 0; j < nums.size(); j++)
		{
			// calculate which operations result in fewest sequence of calculations to arrive at i
			if (i >= nums[j])
			{
				if (nums[j] == 1)
				{
					numOps = minOp[i - nums[j]] + 1;
					count = 1;
				}
				else if (nums[j] == 2 && i % nums[j] == 0)
				{
					if (minOp[(i / nums[j])] + 1 < numOps)
					{
						numOps = minOp[(i / nums[j])] + 1;
						count = 2;
					}
				}
				else if (nums[j] == 3 && i % nums[j] == 0)
				{
					if (minOp[(i / nums[j])] + 1 < numOps)
					{
						numOps = minOp[(i / nums[j])] + 1;
						count = 3;
					}
				}
			}
		}

		// update minOp with fewest # of calculations
		// update cal dictionary based on the smallest sequence of calculations to arrive at i
		if (numOps < minOp[i])
		{
			minOp[i] = numOps;
			if (count == 1)
			{
				cal.insert(std::pair<int, vector<int> >(i, vector<int>{cal.at(i - 1)}));
				cal.at(i).push_back(cal.at(i - 1).back() + 1);
			}
			else if (count == 2)
			{
				cal.insert(std::pair<int, vector<int> >(i, vector<int>{cal.at(i / 2)}));
				cal.at(i).push_back(cal.at(i / 2).back() * 2);
			}
			else if (count == 3)
			{
				cal.insert(std::pair<int, vector<int> >(i, vector<int>{cal.at(i / 3)}));
				cal.at(i).push_back(cal.at(i / 3).back() * 3);
			}
		}	
	}
	return cal.at(n);
}