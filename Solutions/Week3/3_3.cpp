#include <vector>
#include <algorithm>
#include <functional>

using std::vector;

int compute_min_refills(int dist, int tank, vector<int>& stops) {
    
    stops.insert(stops.begin(), 0);
    stops.insert(stops.end(), dist);

    int n = stops.size();
    int refills = 0; // To keep track of how many times in total tank was refilled
    int tank_refills = tank; // To keep track of total tank was fills
    int filled = 1; // To keep track of how many times in total tank was filled

    for (int i = 1; i < n - 1; i++) {

        // If difference between two gas stations is greater than tank capacity, impossible
        if ((stops[i + 1] - stops[i]) > tank) {
            return -1;
        }
    }

    while (stops.size() > 0) {

        vector<int> stations_remaining(stops);

        if (refills > 0) {
            tank_refills = tank * filled;
        }

        // Find max distance the car can go before needing refill
        for (int j = 0; j <= stations_remaining.size() - 1; j++) {

            stations_remaining[j] = std::abs(tank_refills - stations_remaining[j]);

        }
        int min_element = std::distance(stations_remaining.begin(), std::min_element(stations_remaining.begin(), stations_remaining.end()));
        
        // Remove gas stations that have been traveled past
        stops.erase(stops.begin(), stops.begin() + min_element + 1);

        if (stops.size() > 0) {
            refills += 1;
            filled += 1;
        }
 
    }

    return refills;

          
}