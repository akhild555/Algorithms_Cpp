#pragma once
#include <vector>
#include <string>

int get_change(int m);

std::vector<int> optimal_sequence(int n);

int edit_distance(const std::string& str1, const std::string& str2);

int lcs2(std::vector<int>& a, std::vector<int>& b);

int lcs3(std::vector<int>& a, std::vector<int>& b, std::vector<int>& c);