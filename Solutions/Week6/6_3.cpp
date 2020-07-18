#include <cassert>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>


using std::vector;
using std::string;


long long eval(long long a, long long b, char op) {
    if (op == '*') {
        return a * b;
    }
    else if (op == '+') {
        return a + b;
    }
    else if (op == '-') {
        return a - b;
    }
    else {
        assert(0);
    }
}

template <size_t size_x, size_t size_y> // to pass in array to function

std::pair<int, int> MinAndMax(int i, int j, std::string operations, int (&min)[size_x][size_y], int(&max)[size_x][size_y])
{
    int min1 = std::numeric_limits<int>::max();
    int max1 = std::numeric_limits<int>::min();

    for (int k = i; k <= j - 1; k++)
    {
        int a = eval(max[i][k], max[k + 1][j], operations[k]);
        int b = eval(max[i][k], min[k + 1][j], operations[k]);
        int c = eval(min[i][k], max[k + 1][j], operations[k]);
        int d = eval(min[i][k], min[k + 1][j], operations[k]);
        min1 = std::min(min1, std::min(std::min(a, b), std::min(c, d)));
        max1 = std::max(max1, std::max(std::max(a, b), std::max(c, d)));
    }
    return std::make_pair(min1, max1);
}


long long get_maximum_value(const string& exp) {
    
    // extract integers from exp

    int len = exp.length();
    std::vector<int> numbers;
    std::string eval;
    for (size_t i = 0; i < len; i++)
    {
        if (i % 2 == 0)
        {
            numbers.push_back((int)(exp[i] - '0'));
        }
        else
        {
            eval += exp[i];
        }
    }

    int min[10][10] = { 0 };
    int max[10][10] = { 0 };

    // fill diagonals in array

    for (size_t i = 0; i < numbers.size(); i++)
    {
        min[i][i] = numbers[i];
        max[i][i] = numbers[i];
    }

    // fill out array subproblems

    for (int s = 1; s < numbers.size(); s++)
    {
        for (int i = 0; i < numbers.size() - s; i++)
        {
            int j = i + s;
            std::pair<int, int> m = MinAndMax(i, j, eval, min, max);
            min[i][j] = m.first;
            max[i][j] = m.second;
        }
    }
    return max[0][numbers.size()-1];
}