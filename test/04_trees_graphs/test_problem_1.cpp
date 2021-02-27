#include "chapter_4.h"

#include "gtest/gtest.h"

using namespace std;

Graph<BFSVertex> CreateGraph1() {
    Graph<BFSVertex> gr(4);
    gr.AddEdge(0, 1);
    gr.AddEdge(1, 2);
    gr.AddEdge(2, 3);

    return gr;
}

Graph<BFSVertex> CreateGraph2() {
    Graph<BFSVertex> gr(4);
    gr.AddDEdge(0, 1);
    gr.AddDEdge(1, 2);
    gr.AddDEdge(2, 3);

    return gr;
}

Graph<BFSVertex> CreateGraph3() {
    Graph<BFSVertex> gr(8);
    gr.AddDEdge(0, 1);
    gr.AddDEdge(1, 2);
    gr.AddDEdge(0, 3);
    gr.AddDEdge(3, 4);
    gr.AddDEdge(3, 5);
    gr.AddDEdge(4, 5);
    gr.AddDEdge(4, 6);
    gr.AddDEdge(5, 7);
    gr.AddDEdge(5, 6);
    gr.AddDEdge(6, 7);

    return gr;
}

Graph<BFSVertex> CreateGraph4() {
    Graph<BFSVertex> gr(8);
    gr.AddEdge(0, 1);
    gr.AddEdge(1, 2);
    gr.AddEdge(0, 3);
    gr.AddEdge(3, 4);
    gr.AddEdge(3, 5);
    gr.AddEdge(4, 5);
    gr.AddEdge(4, 6);
    gr.AddEdge(5, 7);
    gr.AddEdge(5, 6);
    gr.AddEdge(6, 7);

    return gr;
}

TEST(Ch4Problem1, TestBFS1) {
    auto gr = CreateGraph1();

    BFS(gr, 0);

    for (VertexId v = 0; v < gr.GetVertexNumber(); ++v) {
        const auto& vertex = gr.GetVertex(v);
        EXPECT_TRUE(vertex.visited);
        EXPECT_EQ(vertex.dist, v);
        auto p = (v == 0) ? NIL : v - 1;
        EXPECT_EQ(vertex.parent, p);
    }

    gr = CreateGraph1();

    BFS(gr, 2);
    for (VertexId v = 0; v < 2; ++v) {
        const auto& vertex = gr.GetVertex(v);
        EXPECT_FALSE(vertex.visited);
        EXPECT_EQ(vertex.dist, -1);
        EXPECT_EQ(vertex.parent, NIL);
    }
    for (VertexId v = 2; v < gr.GetVertexNumber(); ++v) {
        const auto& vertex = gr.GetVertex(v);
        EXPECT_TRUE(vertex.visited);
        EXPECT_EQ(vertex.dist, v - 2);
        auto p = (v == 2) ? NIL : v - 1;
        EXPECT_EQ(vertex.parent, p);
    }
}

TEST(Ch4Problem1, TestBFS2) {
    auto gr = CreateGraph2();

    BFS(gr, 0);

    for (VertexId v = 0; v < gr.GetVertexNumber(); ++v) {
        const auto& vertex = gr.GetVertex(v);
        EXPECT_TRUE(vertex.visited);
        EXPECT_EQ(vertex.dist, v);
        auto p = (v == 0) ? NIL : v - 1;
        EXPECT_EQ(vertex.parent, p);
    }

    gr = CreateGraph2();

    BFS(gr, 2);

    for (VertexId v = 0; v < gr.GetVertexNumber(); ++v) {
        EXPECT_TRUE(gr.GetVertex(v).visited);
    }

    EXPECT_EQ(gr.GetVertex(2).parent, NIL);
    EXPECT_EQ(gr.GetVertex(1).parent, 2);
    EXPECT_EQ(gr.GetVertex(3).parent, 2);
    EXPECT_EQ(gr.GetVertex(0).parent, 1);

    EXPECT_EQ(gr.GetVertex(2).dist, 0);
    EXPECT_EQ(gr.GetVertex(1).dist, 1);
    EXPECT_EQ(gr.GetVertex(3).dist, 1);
    EXPECT_EQ(gr.GetVertex(0).dist, 2);
}

TEST(Ch4Problem1, TestBFS3) {
    auto gr = CreateGraph3();

    BFS(gr, 0);
    for (VertexId v = 0; v < gr.GetVertexNumber(); ++v) {
        EXPECT_TRUE(gr.GetVertex(v).visited);
    }

    EXPECT_EQ(gr.GetVertex(2).dist, 2);
    EXPECT_EQ(gr.GetVertex(2).parent, 1);
    EXPECT_EQ(gr.GetVertex(4).dist, 2);
    EXPECT_EQ(gr.GetVertex(5).dist, 2);
    EXPECT_EQ(gr.GetVertex(6).dist, 3);
    EXPECT_EQ(gr.GetVertex(7).dist, 3);
}

TEST(Ch4Problem1, MainTest) {
    auto gr = CreateGraph4();

    EXPECT_TRUE(IsReachable(gr, 0, 1));
    EXPECT_TRUE(IsReachable(gr, 0, 2));
    EXPECT_TRUE(IsReachable(gr, 0, 3));
    EXPECT_TRUE(IsReachable(gr, 0, 4));
    EXPECT_TRUE(IsReachable(gr, 0, 5));
    EXPECT_TRUE(IsReachable(gr, 6, 6));
    EXPECT_TRUE(IsReachable(gr, 6, 7));

    EXPECT_FALSE(IsReachable(gr, 3, 2));
    EXPECT_FALSE(IsReachable(gr, 6, 4));
    EXPECT_FALSE(IsReachable(gr, 4, 0));
    EXPECT_FALSE(IsReachable(gr, 5, 4));
    EXPECT_FALSE(IsReachable(gr, 1, 0));
}