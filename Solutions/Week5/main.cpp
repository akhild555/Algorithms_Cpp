#include <iostream>
#include "week5.h"
#include <vector>


int main() {

	// Switch which problem you want to run from week 5 assignment //

	int problem = 2;


	switch (problem) {

	case 1:
	{
		int m;
		std::cin >> m;
		std::cout << get_change(m) << '\n';
	}

	case 2:
	{
		int n;
		std::cin >> n;
		std::vector<int> sequence = optimal_sequence(n);
		std::cout << sequence.size() - 1 << std::endl;
		for (size_t i = 0; i < sequence.size(); ++i) {
			std::cout << sequence[i] << " ";
		}
	}

	}
}
