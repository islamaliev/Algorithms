//
// Created by Islam Aliev on 11/08/15.
// Copyright (c) 2015 me. All rights reserved.
//

#include "QuickSort.h"
#include "InsertionSort.h"

void QuickSort::sort(std::vector<int>& arr) {
    unsigned long size = arr.size();
    if (size <= 3) {
        InsertionSort insertionSort;
        insertionSort.sort(arr);
        return;
    }
    // shuffle
    sort(arr, 0, size - 1);
}

void QuickSort::sort(std::vector<int>& arr, unsigned long lo, unsigned long hi) {
    unsigned long i = partition(arr, lo, hi);
    if (i - lo > 1) {
        sort(arr, lo, i - 1);
    }
    if (hi - i > 1) {
        sort(arr, i + 1, hi);
    }
}

unsigned long QuickSort::partition(std::vector<int>& arr, unsigned long lo, unsigned long hi) {
    using std::swap;
    unsigned long i(lo);
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
