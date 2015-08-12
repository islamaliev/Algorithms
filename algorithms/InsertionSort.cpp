#include "InsertionSort.h"

void InsertionSort::sort(std::vector<int>& arr) {
    unsigned long size = arr.size();
    for (unsigned long i(1); i < size; i++) {
        unsigned long j(i);
        while (j > 0 && arr[j] < arr[j - 1]) {
            using std::swap;
            swap(arr[j], arr[j - 1]);
            j--;
        }
    }
}
