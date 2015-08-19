#include <gmock/gmock.h>
#include "KnuthShuffle.h"

class KnuthShuffleTest : public testing::Test {
public:
    void SetUp() override {
    }

    void sh(std::initializer_list<int> list) {
        actual = list;
        shuffle.shuffle(actual);
    }

    void an(std::initializer_list<int> list) {
        std::vector<int> expected(list);
        unsigned long size = expected.size();
        float badShuffleCount(0);
        for (int i(0); i < size; i++) {
            int actualVal = actual[i];
            auto it = std::find(expected.begin(), expected.end(), actualVal);
            if (it == expected.end()) {
                badShuffleCount = size;
                break;
            }
            int expectedIndex = std::distance(expected.begin(), it);
            if (i == expectedIndex) {
                badShuffleCount++;
            } else if (i != 0 && i - 1 == expectedIndex) {
                badShuffleCount++;
            } else if (i != size - 1 && i + 1 == expectedIndex) {
                badShuffleCount++;
            }
        }

        ASSERT_LT(badShuffleCount / size, 0.6f);
    }

    std::vector<int> actual;
    KnuthShuffle shuffle;
};

TEST_F(KnuthShuffleTest, Empty) {
    std::vector<int> vec;
    shuffle.shuffle(vec);
}

TEST_F(KnuthShuffleTest, One) {
    std::vector<int> actual = {1};
    std::vector<int> expected = {1};
    shuffle.shuffle(actual);
    EXPECT_THAT(actual, ::testing::ContainerEq(expected));
}

TEST_F(KnuthShuffleTest, Two) {
    std::vector<int> actual = {1, 2};
    std::vector<int> expected = {2, 1};
    shuffle.shuffle(actual);
    EXPECT_THAT(actual, ::testing::ContainerEq(expected));
}

TEST_F(KnuthShuffleTest, Many) {
    sh({1, 2, 3, 4, 5, 6, 7, 8, 9});
    an({1, 2, 3, 4, 5, 6, 7, 8, 9});
}

TEST_F(KnuthShuffleTest, Many2) {
    sh({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15});
    an({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15});
}
