#include <vector>

std::vector<int> MergeSort2(std::vector<int> A, long long& ref);
std::vector<int> Merge2(std::vector<int> B, std::vector<int> C, long long& ref);



long long get_number_of_inversions(std::vector<int>& a, std::vector<int>& b, size_t left, size_t right) {
	long long number_of_inversions = 0;
	if (right <= left + 1) return number_of_inversions;
	std::vector<int> sorted_a = MergeSort2(a, number_of_inversions);
	return number_of_inversions;
}


std::vector<int> MergeSort2(std::vector<int> A, long long& ref)
{
	if (A.size() == 1)
	{
		return A;
	}

	int half = A.size() / 2;

	std::vector<int> vec1(A.begin(), A.begin() + half);
	std::vector<int> vec2(A.begin() + half, A.end());

	// recursive calls to break up vector
	std::vector<int> B = MergeSort2(vec1, ref);
	std::vector<int> C = MergeSort2(vec2, ref);

	std::vector<int> sorted_A = Merge2(B, C, ref);

	return sorted_A;
}

std::vector<int> Merge2(std::vector<int> B, std::vector<int> C, long long& ref)
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
			ref++; // count number of inversions
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