#pragma once


#include <vector>

class QuickSort {
public:
    void sort(std::vector<int>& arr);

private:
    void sort(std::vector<int>& arr, unsigned long lo, unsigned long hi);

    unsigned long partition(std::vector<int>& arr, unsigned long lo, unsigned long hi);
};

