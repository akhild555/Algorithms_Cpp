# include <iostream>
#include <vector>
#include <algorithm>
#include "week1.h"

int main() {


    // Switch which problem you want to run from week 1 assignment //
    int problem = 2;

    switch (problem){

    case 1: {
        int a = 0;
        int b = 0;
        std::cin >> a;
        std::cin >> b;
        std::cout << sum_of_two_digits(a, b);
        return 0;
    }
    case 2: {
        int n;
        std::cin >> n;
        std::vector<int> numbers(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> numbers[i];
        }

        std::cout << MaxPairwiseProduct(numbers) << "\n";
        return 0;
    }
    }

}