#include <vector>
#include <numeric>
#include "week4.h"

using std::vector;

// create vector of numbers in segement and use binary search to see if points exist on segment
vector<int> fast_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
    vector<int> cnt(points.size());
    for (size_t i = 0; i < points.size(); i++)
    {
        for (size_t j = 0; j < starts.size(); j++)
        {
            vector<int> range(ends[j] - starts[j] + 1);
            std::iota(std::begin(range), std::end(range), starts[j]);
            int exists = binary_search(range, points[i]);
            if (exists != -1)
            {
                cnt[i]++;
            }
        }
    }


    return cnt;
}

vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
    vector<int> cnt(points.size());
    for (size_t i = 0; i < points.size(); i++) {
        for (size_t j = 0; j < starts.size(); j++) {
            cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
        }
    }
    return cnt;
}   