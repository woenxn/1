#include <gtest/gtest.h>
#include "deque.h"

TEST(DequeTest, DefaultConstructor)
{
    Deque d;
    EXPECT_EQ(d.get_size(), 0);
    EXPECT_TRUE(d.is_empty());
    EXPECT_EQ(d.to_string(), "Empty");
}

TEST(DequeTest, InitializerList)
{
    Deque d = {10, 20, 30};
    EXPECT_EQ(d.get_size(), 3);
    EXPECT_EQ(d[0], 10);
    EXPECT_EQ(d[2], 30);
}

TEST(DequeTest, CopyLogic)
{
    Deque d1 = {1, 2, 3};
    Deque d2 = d1;
    EXPECT_EQ(d2.to_string(), d1.to_string());

    d2[0] = 99;
    EXPECT_NE(d2[0], d1[0]);
}

TEST(DequeTest, AssignmentOperator)
{
    Deque d1 = {7, 8, 9};
    Deque d2;
    d2 = d1;
    EXPECT_EQ(d2.to_string(), "7 8 9");
}

TEST(DequeTest, PushFront)
{
    Deque d = {2, 3};
    d.push_front(1);
    EXPECT_EQ(d.to_string(), "1 2 3");
}

TEST(DequeTest, PushBack)
{
    Deque d = {1, 2};
    d.push_back(3);
    EXPECT_EQ(d.to_string(), "1 2 3");
}

TEST(DequeTest, PopFront)
{
    Deque d = {10, 20, 30};
    int val = d.pop_front();
    EXPECT_EQ(val, 10);
    EXPECT_EQ(d.to_string(), "20 30");
    EXPECT_EQ(d.get_size(), 2);
}

TEST(DequeTest, PopBack)
{
    Deque d = {10, 20, 30};
    int val = d.pop_back();
    EXPECT_EQ(val, 30);
    EXPECT_EQ(d.to_string(), "10 20");
    EXPECT_EQ(d.get_size(), 2);
}

TEST(DequeTest, FrontBack)
{
    Deque d = {5, 10, 15};
    EXPECT_EQ(d.front(), 5);
    EXPECT_EQ(d.back(), 15);

    d.front() = 55;
    d.back() = 115;
    EXPECT_EQ(d.to_string(), "55 10 115");
}

TEST(DequeTest, EmptyExceptions)
{
    Deque d;
    EXPECT_THROW(d.pop_front(), std::out_of_range);
    EXPECT_THROW(d.pop_back(), std::out_of_range);
    EXPECT_THROW(d.front(), std::out_of_range);
    EXPECT_THROW(d.back(), std::out_of_range);
    EXPECT_THROW(d[0], std::out_of_range);
}

TEST(DequeTest, IndexOfOperator)
{
    Deque d = {100, 200, 300};
    EXPECT_EQ(d[1], 200);
    d[1] = 250;
    EXPECT_EQ(d[1], 250);
    EXPECT_THROW(d[5], std::out_of_range);
}
