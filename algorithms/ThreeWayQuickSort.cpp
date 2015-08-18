#include "ThreeWayQuickSort.h"
#include "InsertionSort.h"
#include "KnuthShuffle.h"

void ThreeWayQuickSort::sort(std::vector<int>& arr) {
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

void ThreeWayQuickSort::sort(std::vector<int>& arr, unsigned lo, unsigned hi) {
    unsigned lt;
    unsigned gt;
    partition(arr, lo, hi, lt, gt);
    if (lt - lo > 1) {
        sort(arr, lo, lt - 1);
    }
    if (hi - gt > 1) {
        sort(arr, gt + 1, hi);
    }
}

void ThreeWayQuickSort::partition(std::vector<int>& arr, unsigned lo, unsigned hi, unsigned& lt, unsigned& gt) {
    using std::swap;
    lt = lo;
    gt = hi;
    unsigned i(lo + 1);
    while (i <= gt) {
        if (arr[i] < arr[lt]) {
            swap(arr[i++], arr[lt++]);
        } else if (arr[i] > arr[lt]) {
            swap(arr[i], arr[gt--]);
        } else {
            i++;
        }
    }
}
