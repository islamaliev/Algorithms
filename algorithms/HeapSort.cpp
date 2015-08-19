#include "HeapSort.h"

void HeapSort::sort(std::vector<int>& arr) {
    vec = &arr;
    size = (int) arr.size();
    for (int i = size / 2; i > 0; i--) {
        sink(arr, i);
    }
    using std::swap;
    while (size > 1) {
        exch(arr, 1, size);
        size--;
        sink(arr, 1);
    }
}

void HeapSort::sink(std::vector<int>& arr, int index) {
    while (index * 2 <= size) {
        int maxChildIndex = index * 2;
        if (maxChildIndex < size && less(arr, maxChildIndex, maxChildIndex + 1)) {
            maxChildIndex++;
        }
        if (less(arr, index, maxChildIndex)) {
            exch(arr, index, maxChildIndex);
            index = maxChildIndex;
        } else {
            break;
        }
    }
}

void HeapSort::exch(std::vector<int>& arr, int index1, int index2) {
    using std::swap;
    swap(arr[index1 - 1], arr[index2 - 1]);
}

bool HeapSort::less(std::vector<int>& arr, int index1, int index2) {
    return arr[index1 - 1] < arr[index2 - 1];
}
