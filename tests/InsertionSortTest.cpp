#include <gmock/gmock.h>
#include "InsertionSort.h"

class InsertionSortTest : public testing::Test {
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
        sorter.sort(vec);
    }

    void a(std::initializer_list<int> list) {
        std::vector<int> expected(list);

//        EXPECT_TRUE(ArraysMatch(expected, vec));
        EXPECT_THAT(vec, ::testing::ContainerEq(expected));
    }

    std::vector<int> vec;
    InsertionSort sorter;
};

TEST_F(InsertionSortTest, Empty) {
    std::vector<int> vec;
    sorter.sort(vec);
}

TEST_F(InsertionSortTest, SortOneElement) {
    s({1});
    a({1});
}

TEST_F(InsertionSortTest, SortTwoOrderedElements) {
    s({1, 2});
    a({1, 2});
}

TEST_F(InsertionSortTest, SortTwoUnorderedElements) {
    s({2, 1});
    a({1, 2});
}

TEST_F(InsertionSortTest, SortBigReversed) {
    s({9, 8, 7, 6, 5, 4, 3, 2, 1});
    a({1, 2, 3, 4, 5, 6, 7, 8, 9});
}

TEST_F(InsertionSortTest, SortBigRandom) {
    s({5, 8, 1, 6, 9, 4, 3, 2, 7});
    a({1, 2, 3, 4, 5, 6, 7, 8, 9});
}

TEST_F(InsertionSortTest, SortBigRandomWithDuplicates) {
    s({5, 2, 5, 8, 1, 6, 9, 4, 2, 3, 1, 2, 8, 2, 7});
    a({1, 1, 2, 2, 2, 2, 3, 4, 5, 5, 6, 7, 8, 8, 9});
}