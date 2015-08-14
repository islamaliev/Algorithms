#include "InsertionSort.h"

void InsertionSort::sort(std::vector<int>& arr) {
    unsigned size = (unsigned) arr.size();
    for (unsigned i(1); i < size; i++) {
        unsigned j(i);
        while (j > 0 && arr[j] < arr[j - 1]) {
            using std::swap;
            swap(arr[j], arr[j - 1]);
            j--;
        }
    }
}
