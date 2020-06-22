#pragma once
#include <vector>



int linear_search(const std::vector<int>& a, int x);

int binary_search(const std::vector<int>& a, int x);

int get_majority_element(std::vector<int>& a, int left, int right);

void randomized_quick_sort(std::vector<int>& a, int l, int r);

std::vector<int> Merge(std::vector<int> B, std::vector<int> C);

long long get_number_of_inversions(std::vector<int>& a, std::vector<int>& b, size_t left, size_t right);

std::vector<int> fast_count_segments(std::vector<int> starts, std::vector<int> ends, std::vector<int> points);

std::vector<int> naive_count_segments(std::vector<int> starts, std::vector<int> ends, std::vector<int> points);