#include "PriorityQueue.h"

void PriorityQueue::insert(int val) {
    vec.push_back(val);
    swim(size());
}

int PriorityQueue::delMax() {
    using std::swap;
    int maxVal = vec[1];
    swap(vec[1], vec[size()]);
    vec.pop_back();
    sink(1);
    return maxVal;
}

int PriorityQueue::max() {
    return vec[1];
}

int PriorityQueue::size() {
    return (int) vec.size() - 1;
}

void PriorityQueue::clear() {
    vec.clear();
    vec.push_back(0);
}

void PriorityQueue::sink(int index) {
    using std::swap;
    while (index * 2 < size()) {
        int maxChildIndex = index * 2;
        if (maxChildIndex < size() && vec[maxChildIndex + 1] > vec[maxChildIndex]) {
            maxChildIndex++;
        }
        if (vec[index] < vec[maxChildIndex]) {
            swap(vec[index], vec[maxChildIndex]);
            index = maxChildIndex;
        } else {
            break;
        }
    }
}

void PriorityQueue::swim(int index) {
    using std::swap;
    int parentIndex = index / 2;
    while (index > 1 && vec[parentIndex] < vec[index]) {
        swap(vec[parentIndex], vec[index]);
        index = parentIndex;
        parentIndex = parentIndex / 2;
    }
}

PriorityQueue::PriorityQueue() {
    clear();
}
