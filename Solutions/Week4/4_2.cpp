#include <vector>

std::vector<int> Merge(std::vector<int> B, std::vector<int> C);

std::vector<int> MergeSort(std::vector<int> A)
{
	if (A.size() == 1)
	{
		return A;
	}

	int half = A.size() / 2;

	std::vector<int> vec1(A.begin(), A.begin() + half);
	std::vector<int> vec2(A.begin() + half, A.end());

	// recursive calls to break up vector
	std::vector<int> B = MergeSort(vec1);
	std::vector<int> C = MergeSort(vec2);

	std::vector<int> sorted_A = Merge(B, C);

	return sorted_A;
}

std::vector<int> Merge(std::vector<int> B, std::vector<int> C)
{
	std::vector<int> D(B.size() + C.size());
	int count = 0;
	while (B.size() > 0 && C.size() > 0)
	{
		int b = B[0];
		int c = C[0];
		if (b <= c)
		{
			B.erase(B.begin());
			D[count] = b;
			count += 1;
		}
		else
		{
			C.erase(C.begin());
			D[count] = c;
			count += 1;
		}
	}

	std::vector<int> remainder = B.size() > C.size() ? B : C; // find which vector still has remaining elements

	// add remaining elements to D
	for (size_t i = 0; i < remainder.size(); ++i)
	{
		D[count] = remainder[i];
		count += 1;
	}
	return D;
}



int get_majority_element(std::vector<int>& a, int left, int right) {
	//if (left == right) return -1;
	//if (left + 1 == right) return a[left];


	// sort vector using mergesort
	std::vector<int> sorted_a = MergeSort(a);

	// find majority element if it exists
	for (size_t i = 0; i < sorted_a.size(); ++i)
	{
		int currentElement = sorted_a[i];
		int count = 0;
		for (size_t j = 0; j < sorted_a.size(); ++j)
		{
			if (sorted_a[j] == currentElement)
			{
				count += 1;
			}
		}
		if (count > sorted_a.size() / 2)
		{
			return 1;
		}
	}

	return 0;
}
