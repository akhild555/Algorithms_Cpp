#include <iostream>
#include "week5.h"

int main() {

	// Switch which problem you want to run from week 5 assignment //

	int problem = 5;


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

	case 4:
	{
		size_t n;
		std::cin >> n;
		std::vector<int> a(n);
		for (size_t i = 0; i < n; i++) {
			std::cin >> a[i];
		}

		size_t m;
		std::cin >> m;
		std::vector<int> b(m);
		for (size_t i = 0; i < m; i++) {
			std::cin >> b[i];
		}

		std::cout << lcs2(a, b) << std::endl;
	}

	case 5:
	{
		size_t an;
		std::cin >> an;
		std::vector<int> a(an);
		for (size_t i = 0; i < an; i++) {
			std::cin >> a[i];
		}
		size_t bn;
		std::cin >> bn;
		std::vector<int> b(bn);
		for (size_t i = 0; i < bn; i++) {
			std::cin >> b[i];
		}
		size_t cn;
		std::cin >> cn;
		std::vector<int> c(cn);
		for (size_t i = 0; i < cn; i++) {
			std::cin >> c[i];
		}
		std::cout << lcs3(a, b, c) << std::endl;
	}

	}
}
