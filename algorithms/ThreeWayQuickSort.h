#pragma once


#include <vector>

class ThreeWayQuickSort {
public:
    void sort(std::vector<int>& arr);

private:
    void sort(std::vector<int>& arr, unsigned lo, unsigned hi);

    void partition(std::vector<int>& arr, unsigned lo, unsigned hi, unsigned& lt, unsigned& gt);
};

