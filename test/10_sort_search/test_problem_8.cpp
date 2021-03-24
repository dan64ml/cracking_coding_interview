#include "chapter_10.h"

#include "gtest/gtest.h"

#include <vector>
#include <sstream>

using namespace std;
using namespace ch10;

TEST(Ch10Problem8, Test1) {
    vector<int> vec {1, 3, 2, 55, 24, 11};
    stringstream ss;

    DisplayDublicates(ss, vec);
    auto result = ss.str();
    EXPECT_EQ(result, "");
}

TEST(Ch10Problem8, Test2) {
    vector<int> vec {1, 3, 2, 55, 24, 11, 3, 3, 15, 2};
    stringstream ss;

    DisplayDublicates(ss, vec);
    auto result = ss.str();
    EXPECT_EQ(result, "3,3,2,");
}

TEST(Ch10Problem8, Test3) {
    vector<int> vec {1, 3, 2, 55, 7, 7, 7, 7, 7, 7};
    stringstream ss;

    DisplayDublicates(ss, vec);
    auto result = ss.str();
    EXPECT_EQ(result, "7,7,7,7,7,");
}
