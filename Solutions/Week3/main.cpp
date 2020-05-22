#include <iostream>
#include <vector>
#include "week3.h"
#include <algorithm>


using std::cin;
using std::cout;
using std::vector;
using std::max;

int main() {

	// Switch which problem you want to run from week 3 assignment //

	int problem = 5;
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

	case 3: {

		int d = 0;
		cin >> d;
		int m = 0;
		cin >> m;
		int n = 0;
		cin >> n;

		vector<int> stops(n);
		for (size_t i = 0; i < n; ++i)
			cin >> stops.at(i);

		cout << compute_min_refills(d, m, stops) << "\n";
	}

	case 4: {

		size_t n;
		std::cin >> n;
		vector<int> a(n), b(n);
		for (size_t i = 0; i < n; i++) {
			std::cin >> a[i];
		}
		for (size_t i = 0; i < n; i++) {
			std::cin >> b[i];
		}
		std::cout << max_dot_product(a, b) << std::endl;
	}

	case 5: {

		int n;
		std::cin >> n;
		vector<Segment> segments(n);
		for (size_t i = 0; i < segments.size(); ++i) {
			std::cin >> segments[i].start >> segments[i].end;
		}
		vector<int> points = optimal_points(segments);
		std::cout << points.size() << "\n";
		for (size_t i = 0; i < points.size(); ++i) {
			std::cout << points[i] << " ";
		}
	}

	}

}