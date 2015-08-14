#pragma once


#include <vector>

class QuickSort {
public:
    void sort(std::vector<int>& arr);

private:
    void sort(std::vector<int>& arr, unsigned lo, unsigned hi);

    unsigned partition(std::vector<int>& arr, unsigned lo, unsigned hi);
};

