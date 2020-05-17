#include <iostream>
#include "week2.h"

long long int least_common_multiple(long long int a, long long int b)
{
    return (a * b) / greatest_common_divisor(a, b);
}