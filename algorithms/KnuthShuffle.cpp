#include <stdlib.h>
#include <ctime>
#include "KnuthShuffle.h"

void KnuthShuffle::shuffle(std::vector<int>& arr) {
    using std::swap;
    srand((unsigned) std::time(0));
    unsigned long size = arr.size();
    for (int i(1); i < size; i++) {
        int randomIndex = getRandom(i - 1);
        swap(arr[i], arr[randomIndex]);
    }
}

int KnuthShuffle::getRandom(int limit) {
    int divisor = RAND_MAX / (limit+1);
    int returnValue;

    do {
        returnValue = rand() / divisor;
    } while (returnValue > limit);

    return returnValue;
}