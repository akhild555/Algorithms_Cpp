#include <iostream>
#include <vector>

int fibonacci_naive(int n) {
    if (n <= 1)
        return n;

    return fibonacci_naive(n - 1) + fibonacci_naive(n - 2);
}

long long fibonacci_fast(long long n) {
    // write your code here
    std::vector<long long> arr(n + 1);

    if (arr.size() < 2)
    {
        arr[0] = 0;
    }
    else
    {
        arr[0] = 0;
        arr[1] = 1;
    }

    for (int i = 2; i < n + 1; i++)
    {
        arr[i] = (arr[i - 1]) + (arr[i - 2]);
    }
    return arr[n];

}