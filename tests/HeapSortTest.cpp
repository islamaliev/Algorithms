#include <gmock/gmock.h>
#include "HeapSort.h"

class HeapSortTest : public testing::Test {
public:
    void SetUp() override {
    }

    void s(std::initializer_list<int> list) {
        vec = list;
        sorter.sort(vec);
    }

    void a(std::initializer_list<int> list) {
        std::vector<int> expected(list);

        EXPECT_THAT(vec, ::testing::ContainerEq(expected));
    }

    std::vector<int> vec;
    HeapSort sorter;
};

TEST_F(HeapSortTest, Empty) {
    std::vector<int> vec;
    sorter.sort(vec);
}

TEST_F(HeapSortTest, SortOneElement) {
    s({1});
    a({1});
}


TEST_F(HeapSortTest, SortTwoOrderedElements) {
    s({1, 2});
    a({1, 2});
}

TEST_F(HeapSortTest, SortTwoUnorderedElements) {
    s({2, 1});
    a({1, 2});
}

TEST_F(HeapSortTest, SortMediumRandom) {
    s({3, 1, 5, 4, 2});
    a({1, 2, 3, 4, 5});
}

TEST_F(HeapSortTest, SortBigReversed) {
    s({9, 8, 7, 6, 5, 4, 3, 2, 1});
    a({1, 2, 3, 4, 5, 6, 7, 8, 9});
}

TEST_F(HeapSortTest, SortBigRandom) {
    s({5, 8, 1, 6, 9, 4, 3, 2, 7});
    a({1, 2, 3, 4, 5, 6, 7, 8, 9});
}


TEST_F(HeapSortTest, SortSmallRandomWithDuplicates) {
    s({2, 3, 2, 1, 2});
    a({1, 2, 2, 2, 3});
}

TEST_F(HeapSortTest, SortBigRandomWithDuplicates) {
    s({5, 2, 5, 8, 1, 6, 9, 4, 2, 3, 1, 2, 8, 2, 7});
    a({1, 1, 2, 2, 2, 2, 3, 4, 5, 5, 6, 7, 8, 8, 9});
}
