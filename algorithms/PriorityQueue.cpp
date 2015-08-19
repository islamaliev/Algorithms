#include "PriorityQueue.h"

void PriorityQueue::insert(int val) {
    vec.push_back(val);
}

int PriorityQueue::delMax() {
    auto maxIt = getMaxIterator();
    int maxVal = *maxIt;
    vec.erase(maxIt);
    return maxVal;
}

int PriorityQueue::max() {
    return *getMaxIterator();
}

std::vector<int>::iterator PriorityQueue::getMaxIterator() {
    int min = *vec.begin();
    auto minIt = vec.begin();
    for (auto it = vec.begin() + 1; it != vec.end(); it++) {
        if (*it > min) {
            min = *it;
            minIt = it;
        }
    }
    return minIt;
}

int PriorityQueue::size() {
    return vec.size();
}

void PriorityQueue::clear() {
    vec.clear();
}
