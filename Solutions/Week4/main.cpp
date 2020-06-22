#include <iostream>
#include "week4.h"


using std::vector;



int main() {

	// Switch which problem you want to run from week 4 assignment //

	int problem = 5;


	switch (problem) {

	case 1: {
		int n;
		std::cin >> n;
		vector<int> a(n);
		for (size_t i = 0; i < a.size(); i++) {
			std::cin >> a[i];
		}
		int m;
		std::cin >> m;
		vector<int> b(m);
		for (int i = 0; i < m; ++i) {
			std::cin >> b[i];
		}
		for (int i = 0; i < m; ++i) {
			//replace with the call to binary_search when implemented
			std::cout << binary_search(a, b[i]) << ' ';
		}
	}

	case 2:
	{
		int n;
		std::cin >> n;
		vector<int> a(n);
		for (size_t i = 0; i < a.size(); ++i) {
			std::cin >> a[i];
		}
		std::cout << (get_majority_element(a, 0, a.size())) << '\n';
	}

	case 3:
	{
		int n;
		std::cin >> n;
		vector<int> a(n);
		for (size_t i = 0; i < a.size(); ++i) {
			std::cin >> a[i];
		}
		randomized_quick_sort(a, 0, a.size() - 1);
		for (size_t i = 0; i < a.size(); ++i) {
			std::cout << a[i] << ' ';
		}
	}
	
	case 4:
	{
		int n;
		std::cin >> n;
		vector<int> a(n);
		for (size_t i = 0; i < a.size(); i++) {
			std::cin >> a[i];
		}
		vector<int> b(a.size());
		std::cout << get_number_of_inversions(a, b, 0, a.size()) << '\n';
	}

	case 5:
	{
		int n, m;
		std::cin >> n >> m;
		vector<int> starts(n), ends(n);
		for (size_t i = 0; i < starts.size(); i++) {
			std::cin >> starts[i] >> ends[i];
		}
		vector<int> points(m);
		for (size_t i = 0; i < points.size(); i++) {
			std::cin >> points[i];
		}
		//use fast_count_segments
		vector<int> cnt = fast_count_segments(starts, ends, points);
		for (size_t i = 0; i < cnt.size(); i++) {
			std::cout << cnt[i] << ' ';
		}
	}


	}
}
