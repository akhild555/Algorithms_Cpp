#include <iostream>
#include "week5.h"

int main() {

	// Switch which problem you want to run from week 5 assignment //

	int problem = 3;


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

	case 3:
	{
		std::string str1;
		std::string str2;
		std::cin >> str1 >> str2;
		std::cout << edit_distance(str1, str2) << std::endl;
		return 0;
	}
	}
}
