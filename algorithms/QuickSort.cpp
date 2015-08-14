#include "QuickSort.h"
#include "InsertionSort.h"
#include "KnuthShuffle.h"

void QuickSort::sort(std::vector<int>& arr) {
    unsigned size = (unsigned) arr.size();
    if (size <= 6) {
        InsertionSort insertionSort;
        insertionSort.sort(arr);
        return;
    }
    KnuthShuffle shuffler;
    shuffler.shuffle(arr);
    sort(arr, 0, size - 1);
}

void QuickSort::sort(std::vector<int>& arr, unsigned lo, unsigned hi) {
    unsigned i = partition(arr, lo, hi);
    if (i - lo > 1) {
        sort(arr, lo, i - 1);
    }
    if (hi - i > 1) {
        sort(arr, i + 1, hi);
    }
}

unsigned QuickSort::partition(std::vector<int>& arr, unsigned lo, unsigned hi) {
    using std::swap;
    unsigned i(lo);
    lo++;
    while (lo <= hi) {
        if (arr[i] > arr[lo]) {
            lo++;
        } else if (arr[i] < arr[hi]) {
            hi--;
        } else {
            swap(arr[lo], arr[hi]);
            lo++;
            hi--;
        }
    }
    swap(arr[lo - 1], arr[i]);
    return lo - 1;
}
