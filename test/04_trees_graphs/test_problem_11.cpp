#include "chapter_4.h"

#include "gtest/gtest.h"

using namespace std;
using namespace ch04;

TEST(Ch4Problem11, TestNth) {
    RandomBSTree rt;
    rt.AddNode(42);
    rt.AddNode(20);
    rt.AddNode(75);
    rt.AddNode(10);
    rt.AddNode(30);

    EXPECT_EQ(rt.GetNthElement(1)->key, 10);
    EXPECT_EQ(rt.GetNthElement(2)->key, 20);
    EXPECT_EQ(rt.GetNthElement(3)->key, 30);
    EXPECT_EQ(rt.GetNthElement(4)->key, 42);
    EXPECT_EQ(rt.GetNthElement(5)->key, 75);
}

TEST(Ch4Problem11, Trivial) {
    RandomBSTree rt;
    rt.AddNode(42);
    rt.AddNode(20);
    rt.AddNode(75);
    rt.AddNode(10);
    rt.AddNode(30);

    cout << rt.GetRandomNode()->key << endl;
    cout << rt.GetRandomNode()->key << endl;
    cout << rt.GetRandomNode()->key << endl;
    cout << rt.GetRandomNode()->key << endl;
    cout << rt.GetRandomNode()->key << endl;
    cout << rt.GetRandomNode()->key << endl;
    cout << rt.GetRandomNode()->key << endl;
}