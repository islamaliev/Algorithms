#include <gmock/gmock.h>
#include "QuickSort.h"

class QuickSortTest : public testing::Test {
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
    QuickSort qsort;
};

TEST_F(QuickSortTest, Empty) {
    std::vector<int> vec;
    qsort.sort(vec);
}

TEST_F(QuickSortTest, SortOneElement) {
    s({1});
    a({1});
}

TEST_F(QuickSortTest, SortTwoOrderedElements) {
    s({1, 2});
    a({1, 2});
}

TEST_F(QuickSortTest, SortTwoUnorderedElements) {
    s({2, 1});
    a({1, 2});
}

TEST_F(QuickSortTest, SortMediumRandom) {
    s({3, 1, 5, 4, 2});
    a({1, 2, 3, 4, 5});
}

TEST_F(QuickSortTest, SortBigReversed) {
    s({9, 8, 7, 6, 5, 4, 3, 2, 1});
    a({1, 2, 3, 4, 5, 6, 7, 8, 9});
}

TEST_F(QuickSortTest, SortBigRandom) {
    s({5, 8, 1, 6, 9, 4, 3, 2, 7});
    a({1, 2, 3, 4, 5, 6, 7, 8, 9});
}


TEST_F(QuickSortTest, DISABLED_SortSmallRandomWithDuplicates) {
    s({2, 3, 2, 1, 2});
    a({1, 2, 2, 2, 3});
}

TEST_F(QuickSortTest, DISABLED_SortBigRandomWithDuplicates) {
    s({5, 2, 5, 8, 1, 6, 9, 4, 2, 3, 1, 2, 8, 2, 7});
    a({1, 1, 2, 2, 2, 2, 3, 4, 5, 5, 6, 7, 8, 8, 9});
}