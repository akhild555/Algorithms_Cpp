#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

long long max_dot_product(vector<int> a, vector<int> b) {

    long long result = 0;

    // Solution 1

    // sort vectors in descending order
    std::sort(a.begin(), a.end(), std::greater<int>());
    std::sort(b.begin(), b.end(), std::greater<int>());
    for (size_t i = 0; i < a.size(); i++) {
        result += (long long)(a[i]) * b[i];
    }

    // Solution 2

    //while (a.size() > 0) {

    //    long long max_a = *std::max_element(a.begin(), a.end());
    //    int max_b = *std::max_element(b.begin(), b.end());
    //    result += (long long)(max_a)*max_b;
    //    a.erase(std::remove(a.begin(), a.end(), max_a), a.end()); // remove max element in a
    //    b.erase(std::remove(b.begin(), b.end(), max_b), b.end()); // remove max element in b
    //}

    return result;
}