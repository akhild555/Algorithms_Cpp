#include <vector>
#include <numeric>


using std::vector;

vector<int> optimal_summands(int n) {
    vector<int> summands;


    while (std::accumulate(summands.begin(), summands.end(), 0) != n) {
        
        for (int i = 1; i<n; i++) {
            summands.push_back(i); // add next +1 number to end of vector for each loop

            //check if sum of vector is n
            if (std::accumulate(summands.begin(), summands.end(), 0) == n) 
            {
                return summands;
            }
            // check if sum of vector is greater. If so, compensate the last element so sum = n
            else if (std::accumulate(summands.begin(), summands.end(), 0) > n) 
            {
                summands.pop_back(); // remove last element since it makes the sum greater than n
                int vec_sum = std::accumulate(summands.begin(), summands.end(),0);
                int rem = n - vec_sum;
                summands.back() += rem; // increase the value of the current last element so sum is n
                return summands;

            }
        }
    }

}