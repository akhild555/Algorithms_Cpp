#include <iostream>

long long int greatest_common_divisor(long long int a, long long int b)
{
    if (b == 0)
    {
        return a;
    }

    long long int ap = a % b;
    return greatest_common_divisor(b, ap);
}