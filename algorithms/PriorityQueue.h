#pragma once


#include <vector>

class PriorityQueue {
public:
    void insert(int val);

    int delMax();

    int max();

    int size();

    void clear();

private:
    std::vector<int> vec;

    std::vector<int>::iterator getMaxIterator();
};

