#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;


// Two way partition
int partition2(vector<int>& a, int l, int r) {
    int x = a[l];
    int j = l;
    for (int i = l + 1; i <= r; i++) {
        if (a[i] <= x) {
            j++;
            swap(a[i], a[j]);
        }
    }
    swap(a[l], a[j]);
    return j;
}

// Three way partition
std::pair<int,int> partition3(vector<int>& a, int l, int r) {
    int x = a[l];
    int j = l;
    int k = r;
    int i = l;
    while (i <= k) {
        if (a[i] < x) {   
            swap(a[i], a[j]);
            j++;
            i++;
        }
        else if (a[i] > x)
        {   
            swap(a[i], a[k]);            
            k--;
        }
        else
        {
            i++;
        }
    }
    return std::make_pair(j,k);
}

void randomized_quick_sort(vector<int>& a, int l, int r) {
    if (l >= r) {
        return;
    }

    int k = l + rand() % (r - l + 1); // random pivot
    swap(a[l], a[k]);
    std::pair<int,int> m = partition3(a, l, r);

    randomized_quick_sort(a, l, m.first - 1);
    randomized_quick_sort(a, m.second + 1, r);
}