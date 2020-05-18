#include <vector>
#include <algorithm>


using std::vector;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
    
    double value = 0.0;

    int n = values.size();
    vector<int> result(values.size());
    
    // get value per unit weight

    for (int i = 0; i < n; i++) {
        result[i] = values[i] / weights[i];
    }

    int total_weight = 0;
    int remaining_capacity = capacity;

    while (total_weight < capacity) {

        // index of max value per unit weight
        int max_element = std::distance(result.begin(), std::max_element(result.begin(), result.end()));

        if (weights[max_element] <= remaining_capacity) {
            value += double(values[max_element]);
            total_weight += weights[max_element];
            remaining_capacity = capacity - total_weight;
        }

        // add fractional values
        else {
            double item_amount = double (remaining_capacity) / double(weights[max_element]);
            value += item_amount * double(values[max_element]);
            total_weight += item_amount * weights[max_element];
            remaining_capacity = capacity - total_weight;
        }

        // remove bagged item       
        result.erase(result.begin() + max_element);
        weights.erase(weights.begin() + max_element);
        values.erase(values.begin() + max_element);

    }

    return value;
}