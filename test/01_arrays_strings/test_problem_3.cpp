#include "chapter_1.h"

#include "gtest/gtest.h"

#include <string>

using namespace std;

TEST(Ch1Problem3, EmptyString) {
    string str;
    replace_spaces(str, 0);

    EXPECT_EQ(str, string());
}

TEST(Ch1Problem3, FillTest) {
    string in = "nofreespace";
    string out = in;
    replace_spaces(in, in.size());
    EXPECT_EQ(in, out);

    in = "one space  ";
    out = "one%20space";
    replace_spaces(in, 9);
    EXPECT_EQ(in, out);

    in = "two  space    ";
    out = "two%20%20space";
    replace_spaces(in, 10);
    EXPECT_EQ(in, out);

    in = "two different space    ";
    out = "two%20different%20space";
    replace_spaces(in, 19);
    EXPECT_EQ(in, out);

    in = "   ";
    out = "%20";
    replace_spaces(in, 1);
    EXPECT_EQ(in, out);

    in = " first  ";
    out = "%20first";
    replace_spaces(in, 6);
    EXPECT_EQ(in, out);
}