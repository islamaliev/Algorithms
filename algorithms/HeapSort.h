#pragma once


#include <vector>

class HeapSort {
public:
    void sort(std::vector<int>& arr);

private:
    void sink(std::vector<int>& arr, int index);

    bool less(std::vector<int>& arr, int index1, int index2);

    void exch(std::vector<int>& arr, int index1, int index2);

    int size;
};

