#include <algorithm>
#include <climits>
#include <vector>
#include <numeric>

using std::vector;

struct Segment {
    int start, end;
};


// this function calculates how many segments each point falls in
vector<int> remaining_segments(vector<Segment>& segments)  {
    
    vector<int> all_points;
    vector<int> point_count;

    // collect all points into one vector
    for (size_t i = 0; i < segments.size(); ++i) {
        all_points.push_back(segments[i].start);
        all_points.push_back(segments[i].end);
    }

    // get max and min of inputs
    const int max_number = *std::max_element(all_points.begin(), all_points.end());
    const int min_number = *std::min_element(all_points.begin(), all_points.end());

    // count how many segments each point falls in
    int count = 0;
    for (int i = min_number; i <= max_number; i++) {
        for (size_t j = 0; j < segments.size(); ++j) {
            if ((i >= segments[j].start) && (i <= segments[j].end)) {
                count++;
            }
        }
        point_count.push_back(count);
        count = 0;
    }

    return point_count;
};

vector<int> optimal_points(vector<Segment>& segments) {


    vector<int> overlap;
    vector<int> points;
    int counter = 1;

    while (segments.size() > 0) {
                
        vector<int> point_count = remaining_segments(segments);
        int most_points = std::distance(point_count.begin(), std::max_element(point_count.begin(), point_count.end()));
        most_points += counter; // point that falls into most segments
        points.push_back(most_points);
        
        // find segments that do not contain the most_points to a new struct (sub-problem)

        int struct_size = 0;
        vector<int> new_segments_idx;
        for (size_t j = 0; j < segments.size(); ++j) {
            if (!((most_points >= segments[j].start) && (most_points <= segments[j].end))) {
                struct_size++;
                new_segments_idx.push_back(j);
            }

        }

        vector<Segment> segments_new(struct_size);

        // add unaccounted for segments to new struct 

        for (size_t i = 0; i < new_segments_idx.size(); ++i) {
            segments_new[i] = segments[new_segments_idx[i]];
        }

        segments = segments_new;
        if (segments.size() > 0){
            counter = segments[0].start;
        }
        
    }

    return points;
}