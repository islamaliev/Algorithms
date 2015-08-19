#pragma once


#include <vector>

class PriorityQueue {
public:
    PriorityQueue();

    void insert(int val);

    int delMax();

    int max();

    int size();

    void clear();

private:
    void sink(int index);
    void swim(int index);

    std::vector<int> vec;
};

