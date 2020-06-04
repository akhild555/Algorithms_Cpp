#pragma once
#include <vector>

using std::vector;

int money_change(int a);

double get_optimal_value(int capacity, vector<int> weights, vector<int> values);

int compute_min_refills(int dist, int tank, vector<int>& stops);

long long max_dot_product(vector<int> a, vector<int> b);


struct Segment {
    int start, end;
};

vector<int> optimal_points(vector<Segment>& segments);

vector<int> optimal_summands(int n);