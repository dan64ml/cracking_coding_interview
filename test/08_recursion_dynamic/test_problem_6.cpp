#include "chapter_8.h"

#include "gtest/gtest.h"

#include <limits>

using namespace std;
using namespace ch08;

TEST(Ch8Problem6, Test1) {
    stack<char> s1;
    stack<char> s2;
    stack<char> s3;

    s1.push('c');
    s1.push('b');
    s1.push('a');

    Hanoy(s1, s3, s2, 3);
}