#include <gmock/gmock.h>
#include "PriorityQueue.h"

class PriorityQueueTest : public testing::Test {
public:
    void SetUp() override {
    }

    PriorityQueue queue;
};

TEST_F(PriorityQueueTest, InitialInEmpty) {
    ASSERT_EQ(0, queue.size());
}

TEST_F(PriorityQueueTest, AfterAddAndRemoveIsEmpty) {
    queue.insert(1);
    queue.delMax();
    ASSERT_EQ(0, queue.size());
}

TEST_F(PriorityQueueTest, AfterClearIsEmpty) {
    queue.insert(1);
    queue.insert(2);
    queue.clear();
    ASSERT_EQ(0, queue.size());
}

TEST_F(PriorityQueueTest, OneElementIsMax) {
    queue.insert(5);
    ASSERT_EQ(5, queue.max());
}

TEST_F(PriorityQueueTest, IfFewElementsBiggerIsMax) {
    queue.insert(5);
    queue.insert(7);
    queue.insert(6);
    ASSERT_EQ(7, queue.max());
}

TEST_F(PriorityQueueTest, InsertIncreasesSize) {
    queue.insert(5);
    ASSERT_EQ(1, queue.size());
    queue.insert(6);
    ASSERT_EQ(2, queue.size());
    queue.insert(7);
    ASSERT_EQ(3, queue.size());
}

TEST_F(PriorityQueueTest, DelMaxReducesSize) {
    queue.insert(5);
    queue.insert(7);
    queue.insert(6);
    queue.delMax();
    ASSERT_EQ(2, queue.size());
    queue.delMax();
    ASSERT_EQ(1, queue.size());
    queue.delMax();
    ASSERT_EQ(0, queue.size());
}

TEST_F(PriorityQueueTest, DelMaxDeletesInMaxOrder) {
    queue.insert(5);
    queue.insert(7);
    queue.insert(6);
    ASSERT_EQ(7, queue.delMax());
    ASSERT_EQ(6, queue.delMax());
    ASSERT_EQ(5, queue.delMax());
}