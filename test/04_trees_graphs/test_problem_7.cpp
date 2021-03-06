#include "chapter_4.h"

#include "gtest/gtest.h"

using namespace std;
using namespace ch04;

TEST(Ch4Problem7, Trivial) {
    vector<pair<VertexId, VertexId>> dep {{0, 1}};
    auto ret = GetOrder(2, dep);
    EXPECT_EQ(ret, vector<VertexId> ({1, 0}));

    vector<pair<VertexId, VertexId>> dep2 {{0, 1}, {1, 2}};
    auto ret2 = GetOrder(3, dep2);
    EXPECT_EQ(ret2, vector<VertexId> ({2, 1, 0}));

    vector<pair<VertexId, VertexId>> dep3 {{0, 1}, {1, 2}, {2, 0}};
    auto ret3 = GetOrder(3, dep3);
    EXPECT_EQ(ret3.size(), 0);
}

TEST(Ch4Problem7, Test1) {
    vector<pair<VertexId, VertexId>> dep {{3, 0}, {1, 5}, {3, 1}, {0, 5}, {2, 3}};
    auto ret = GetOrder(6, dep);
    
    EXPECT_EQ(ret, vector<VertexId> ({5, 0, 1, 3, 2, 4}));
}

TEST(Ch4Problem7, Test2) {
    vector<pair<VertexId, VertexId>> dep {{8, 7}, {8, 5}, {7, 6}, {5, 6}, 
                                        {5, 3}, {4, 3}, {4, 1}, {4, 0}, {3, 0}};
    auto ret = GetOrder(9, dep);

    for (size_t i = 0; i < ret.size(); ++i) {
        for (auto [slave, master] : dep) {
            if (ret[i] == slave) {
                for (size_t j = i + 1; j < ret.size(); ++j) {
                    EXPECT_NE(master, ret[j]) << "Project " << slave << " before " << master;
                }
            }
        }
    }
}