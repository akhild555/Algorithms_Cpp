#include <iostream>
#include "week6.h"

int main() {

	// Switch which problem you want to run from week 5 assignment //

	int problem = 2	;

	switch (problem) {

	case 1:
	{
		int n, W;
		std::cin >> W >> n;
		vector<int> w(n);
		for (int i = 0; i < n; i++) {
			std::cin >> w[i];
		}
		std::cout << optimal_weight(W, w) << '\n';
	}

	case 2:
	{
		int n;
		std::cin >> n;
		vector<int> A(n);
		for (size_t i = 0; i < A.size(); ++i) {
			std::cin >> A[i];
		}
		std::cout << partition3(A) << '\n';
	}

	case 3:
	{
		std::string s;
		std::cin >> s;
		std::cout << get_maximum_value(s) << '\n';
	}

	}
}
