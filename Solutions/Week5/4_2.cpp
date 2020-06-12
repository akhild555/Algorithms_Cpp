#include <vector>

int get_majority_element(std::vector<int>& a, int left, int right) {
	if (left == right) return -1;
	if (left + 1 == right) return a[left];
	//write your code here

	int half = a.size() / 2;


	return 0;
}