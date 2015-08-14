#pragma once


#include <vector>

class KnuthShuffle {
public:
    void shuffle(std::vector<int>& arr);

private:
    int getRandom(int limit);
};

