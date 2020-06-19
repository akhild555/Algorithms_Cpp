#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;


int Partition(vector<int>& A, int left, int right);
void Quicksort(vector<int>& A, int left, int right);

void Quicksort(vector<int>& A, int left, int right)
{
    if (left >= right)
    {
        return;
    }

    int m = Partition(A, left, right);
    Quicksort(A, left, m - 1);
    Quicksort(A, m + 1, right);
}

int Partition(vector<int>& A, int left, int right)
{
    int x = A[left];
    int j = left;

    for (int i = left + 1; i <= right; ++i)
    {
        if (A[i] <= x)
        {
            j ++;
            swap(A[j], A[i]);
        }
    }
    swap(A[left], A[j]);
    return j;
}


//int partition2(vector<int>& a, int l, int r) {
//    int x = a[l];
//    int j = l;
//    for (int i = l + 1; i <= r; i++) {
//        if (a[i] <= x) {
//            j++;
//            swap(a[i], a[j]);
//        }
//    }
//    swap(a[l], a[j]);
//    return j;
//}
//
//void randomized_quick_sort(vector<int>& a, int l, int r) {
//    if (l >= r) {
//        return;
//    }
//
//    int k = l + rand() % (r - l + 1);
//    swap(a[l], a[k]);
//    int m = partition2(a, l, r);
//
//    randomized_quick_sort(a, l, m - 1);
//    randomized_quick_sort(a, m + 1, r);
//}