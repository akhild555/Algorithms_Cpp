#include <iostream>
#include "week2.h"

int fibonacci_sum_between(int a, int b)
{
    long long d = (fibonacci_fast(b + 2));
    d -= 1;
    long long c = (fibonacci_fast(a + 1) - 1);
    long long e = d - c;
    return e % 10;
}