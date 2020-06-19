#pragma once
#include <vector>



int linear_search(const std::vector<int>& a, int x);

int binary_search(const std::vector<int>& a, int x);

int get_majority_element(std::vector<int>& a, int left, int right);

//void randomized_quick_sort(std::vector<int>& a, int l, int r);

void Quicksort(std::vector<int>& A, int left, int right);