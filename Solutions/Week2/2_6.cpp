#include <iostream>
#include "week2.h"

int fibonacci_sum_last_digit(int a)
{
    return (fibonacci_fast(a + 2) - 1) % 10;
}