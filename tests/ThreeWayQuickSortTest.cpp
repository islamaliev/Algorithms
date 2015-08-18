#include <gmock/gmock.h>
#include "ThreeWayQuickSort.h"

class ThreeWayQuickSortTest : public testing::Test {
public:
    void SetUp() override {
    }

    ::testing::AssertionResult ArraysMatch(std::vector<int>& expected,
            std::vector<int>& actual){
        for (size_t i(0); i < expected.size(); ++i){
            if (expected[i] != actual[i]){
                return ::testing::AssertionFailure() << "array[" << i
                        << "] (" << actual[i] << ") != expected[" << i
                        << "] (" << expected[i] << ")";
            }
        }

        return ::testing::AssertionSuccess();
    }

    void s(std::initializer_list<int> list) {
        vec = list;
        qsort.sort(vec);
    }

    void a(std::initializer_list<int> list) {
        std::vector<int> expected(list);

//        EXPECT_TRUE(ArraysMatch(expected, vec));
        EXPECT_THAT(vec, ::testing::ContainerEq(expected));
    }

    std::vector<int> vec;
    ThreeWayQuickSort qsort;
};

TEST_F(ThreeWayQuickSortTest, Empty) {
    std::vector<int> vec;
    qsort.sort(vec);
}

TEST_F(ThreeWayQuickSortTest, SortOneElement) {
    s({1});
    a({1});
}

TEST_F(ThreeWayQuickSortTest, SortTwoOrderedElements) {
    s({1, 2});
    a({1, 2});
}

TEST_F(ThreeWayQuickSortTest, SortTwoUnorderedElements) {
    s({2, 1});
    a({1, 2});
}

TEST_F(ThreeWayQuickSortTest, SortMediumRandom) {
    s({3, 1, 5, 4, 2});
    a({1, 2, 3, 4, 5});
}

TEST_F(ThreeWayQuickSortTest, bla) {
    s({3, 1, 3, 4, 4});
    a({1, 3, 3, 4, 4});
}

TEST_F(ThreeWayQuickSortTest, SortBigReversed) {
    s({9, 8, 7, 6, 5, 4, 3, 2, 1});
    a({1, 2, 3, 4, 5, 6, 7, 8, 9});
}

TEST_F(ThreeWayQuickSortTest, SortBigRandom) {
    s({5, 8, 1, 6, 9, 4, 3, 2, 7});
    a({1, 2, 3, 4, 5, 6, 7, 8, 9});
}

TEST_F(ThreeWayQuickSortTest, SortSmallRandomWithDuplicates) {
    s({2, 3, 2, 1, 2});
    a({1, 2, 2, 2, 3});
}

TEST_F(ThreeWayQuickSortTest, SortBigRandomWithDuplicates) {
    s({5, 2, 5, 8, 1, 6, 9, 4, 2, 3, 1, 2, 8, 2, 7});
    a({1, 1, 2, 2, 2, 2, 3, 4, 5, 5, 6, 7, 8, 8, 9});
}