#include <iostream>
#include "week4.h"


using std::vector;



int main() {

	// Switch which problem you want to run from week 4 assignment //

	int problem = 2;


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

	}
}
