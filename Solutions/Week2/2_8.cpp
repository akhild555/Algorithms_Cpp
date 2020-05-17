#include <iostream>
#include "week2.h"

int fibonacci_squares(int a)
{
    long long squares1 = fibonacci_fast(a);
    long long squares2 = fibonacci_fast(a) + fibonacci_fast(a - 1);
    int result = (squares1 % 10) * (squares2 % 10);
    return result % 10;
}