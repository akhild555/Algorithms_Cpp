#include <vector>
#include <limits>
#include <algorithm>

using std::vector;
using std::pair;

double naiveClosestPoint(std::vector<std::pair<int, int>>& points);

// sort_points is for creating a vector of x,y pairs and sorting pairs of points by x
std::vector<std::pair<int, int>> sort_points(std::vector<int>& x,std::vector<int>& y)
{
	std::vector<std::pair<int, int>> points;
	points.reserve(x.size());
	std::transform(x.begin(), x.end(), y.begin(), std::back_inserter(points), [](int a, int b) {return std::make_pair(a, b); });
	std::sort(points.begin(), points.end());

	return points;
}

double min_set_distance(std::vector<std::pair<int, int>> A)
{
	if (A.size() <= 3)
	{
		return naiveClosestPoint(A);
	}

	int half = A.size() / 2;

	std::vector<std::pair<int, int>> vec1(A.begin(), A.begin() + half);
	std::vector<std::pair<int, int>> vec2(A.begin() + half, A.end());

	// recursive calls to break up vector
	double B = min_set_distance(vec1);
	double C = min_set_distance(vec2);

	return std::min(B,C);
}

bool compare_pairs_second(const pair<int, int>& a, const pair<int, int>& b)
{
	return a.second < b.second;
}

double naiveClosestPoint(std::vector<std::pair<int, int>>& points)
{
	double min_distance = std::numeric_limits<int>::max();
	for (size_t i = 0; i < points.size(); i++)
	{
		for (size_t j = 0; j < points.size(); j++)

			if (i != j)
			{
				double distance = pow(pow(points[i].first - points[j].first, 2) + 
					pow(points[i].second - points[j].second, 2), 0.5);
				min_distance = distance < min_distance ? distance : min_distance;
			}
	}
	return min_distance;
}

double yClosestPoint(std::vector<std::pair<int, int>>& points)
{
	double min_distance = std::numeric_limits<int>::max();
	for (size_t i = 0; i < points.size(); i++)
	{
		for (size_t j = 0; j < points.size(); j++)
		{
			if (std::abs(int(i - j)) > 7) //if true, the distance between points is greater than current min for sure
			{
				return min_distance;
			}

			if (i != j)
			{
				double distance = pow(pow(points[i].first - points[j].first, 2) + pow(points[i].second - points[j].second, 2), 0.5);
				min_distance = distance < min_distance ? distance : min_distance;
			}
		}
	}
	return min_distance;
}


double minimal_distance(vector<int> x, vector<int> y) {

	std::vector<std::pair<int, int>> points = sort_points(x, y); // first, sort by x values
	double min_sets = min_set_distance(points); // get minimum distance of two sets

	int half = points[points.size() / 2].first;
	std::vector<std::pair<int, int>> close_points;

	// collect points whose x value is less than current minimum distance from n/2
	for (size_t i = 0; i < points.size(); ++i)
	{
		if (std::abs(points[i].first - half) <= min_sets)
		{
			close_points.push_back(points[i]);
		}
	}

	std::sort(close_points.begin(), close_points.end(), compare_pairs_second); //sort by y values
	double min_sets1 = yClosestPoint(close_points); // get minimum distance of reduced set of points

	return std::min(min_sets, min_sets1); // return minimum of two calculated minumums;
}