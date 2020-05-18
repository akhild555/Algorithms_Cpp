#include <iostream>
#include "week3.h"


int main() {

	// Switch which problem you want to run from week 3 assignment //

	int problem = 2;
	int n = 0;

	switch (problem) {

	case 1: {
		std::cin >> n;
		std::cout << money_change(n) << '\n';
	}

	case 2: {

		int n;
		int capacity;
		std::cin >> n >> capacity;
		vector<int> values(n);
		vector<int> weights(n);
		for (int i = 0; i < n; i++) {
			std::cin >> values[i] >> weights[i];
		}

		double optimal_value = get_optimal_value(capacity, weights, values);

		std::cout.precision(10);
		std::cout << optimal_value << std::endl;

	}
	}

}