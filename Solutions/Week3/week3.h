#pragma once
#include <vector>

using std::vector;

int money_change(int a);

double get_optimal_value(int capacity, vector<int> weights, vector<int> values);

int compute_min_refills(int dist, int tank, vector<int>& stops);