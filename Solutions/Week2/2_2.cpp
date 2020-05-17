#include <iostream>
#include <vector>

int fibonacci_last(int n) {

    std::vector<int> arr(n + 1);
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
        arr[i] = (arr[i - 1] + arr[i - 2]) % 10;
    }
    return arr[n];

}