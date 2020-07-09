#include <iostream>
#include "week6.h"

int main() {

	// Switch which problem you want to run from week 5 assignment //

	int problem = 1;

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

	}
}
