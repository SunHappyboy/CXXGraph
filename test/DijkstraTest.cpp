#include "CXXGraph.hpp"
#include "gtest/gtest.h"

TEST(DijkstraTest, correct_example_1) {
  CXXGraph::Node<int> node1("1", 1);
  CXXGraph::Node<int> node2("2", 2);
  CXXGraph::Node<int> node3("3", 3);

  std::pair<const CXXGraph::Node<int> *, const CXXGraph::Node<int> *> pairNode(
      &node1, &node2);
  CXXGraph::DirectedWeightedEdge<int> edge1(1, pairNode, 1);
  CXXGraph::DirectedWeightedEdge<int> edge2(2, node2, node3, 1);
  CXXGraph::UndirectedWeightedEdge<int> edge3(3, node1, node3, 6);

  CXXGraph::T_EdgeSet<int> edgeSet;
  edgeSet.insert(&edge1);
  edgeSet.insert(&edge2);
  edgeSet.insert(&edge3);

  CXXGraph::Graph<int> graph(edgeSet);
  CXXGraph::DijkstraResult res = graph.dijkstra(node1, node3);
  ASSERT_TRUE(res.success);
  ASSERT_EQ(res.errorMessage, "");
  ASSERT_EQ(res.result, 2);
}

TEST(DijkstraTest, correct_example_2) {
  CXXGraph::Node<int> node1("1", 1);
  CXXGraph::Node<int> node2("2", 2);
  CXXGraph::Node<int> node3("3", 3);

  std::pair<const CXXGraph::Node<int> *, const CXXGraph::Node<int> *> pairNode(
      &node1, &node2);
  CXXGraph::DirectedWeightedEdge<int> edge1(1, pairNode, 5);
  CXXGraph::DirectedWeightedEdge<int> edge2(2, node2, node3, 4);
  CXXGraph::UndirectedWeightedEdge<int> edge3(3, node1, node3, 6);

  CXXGraph::T_EdgeSet<int> edgeSet;
  edgeSet.insert(&edge1);
  edgeSet.insert(&edge2);
  edgeSet.insert(&edge3);

  CXXGraph::Graph<int> graph(edgeSet);
  CXXGraph::DijkstraResult res = graph.dijkstra(node1, node3);
  ASSERT_TRUE(res.success);
  ASSERT_EQ(res.errorMessage, "");
  ASSERT_EQ(res.result, 6);
}

TEST(DijkstraTest, correct_example_3) {
  // Example from
  // https://www.analyticssteps.com/blogs/dijkstras-algorithm-shortest-path-algorithm
  CXXGraph::Node<int> nodeA("A", 1);
  CXXGraph::Node<int> nodeB("B", 1);
  CXXGraph::Node<int> nodeC("C", 1);
  CXXGraph::Node<int> nodeD("D", 1);
  CXXGraph::Node<int> nodeE("E", 1);

  CXXGraph::UndirectedWeightedEdge<int> edge1(1, nodeA, nodeB, 3);
  CXXGraph::UndirectedWeightedEdge<int> edge2(2, nodeA, nodeC, 1);
  CXXGraph::UndirectedWeightedEdge<int> edge3(3, nodeB, nodeC, 7);
  CXXGraph::UndirectedWeightedEdge<int> edge4(4, nodeC, nodeD, 2);
  CXXGraph::UndirectedWeightedEdge<int> edge5(5, nodeB, nodeE, 1);
  CXXGraph::UndirectedWeightedEdge<int> edge6(6, nodeB, nodeD, 5);
  CXXGraph::UndirectedWeightedEdge<int> edge7(7, nodeD, nodeE, 7);

  CXXGraph::T_EdgeSet<int> edgeSet;
  edgeSet.insert(&edge1);
  edgeSet.insert(&edge2);
  edgeSet.insert(&edge3);
  edgeSet.insert(&edge4);
  edgeSet.insert(&edge5);
  edgeSet.insert(&edge6);
  edgeSet.insert(&edge7);

  CXXGraph::Graph<int> graph(edgeSet);
  CXXGraph::DijkstraResult res = graph.dijkstra(nodeC, nodeE);
  ASSERT_TRUE(res.success);
  ASSERT_EQ(res.errorMessage, "");
  ASSERT_EQ(res.result, 5);
  res = graph.dijkstra(nodeC, nodeA);
  ASSERT_TRUE(res.success);
  ASSERT_EQ(res.errorMessage, "");
  ASSERT_EQ(res.result, 1);
  res = graph.dijkstra(nodeC, nodeB);
  ASSERT_TRUE(res.success);
  ASSERT_EQ(res.errorMessage, "");
  ASSERT_EQ(res.result, 4);
  res = graph.dijkstra(nodeC, nodeD);
  ASSERT_TRUE(res.success);
  ASSERT_EQ(res.errorMessage, "");
  ASSERT_EQ(res.result, 2);
}

TEST(DijkstraTest, correct_example_4) {
  // Example from
  // https://www.freecodecamp.org/news/dijkstras-shortest-path-algorithm-visual-introduction/
  CXXGraph::Node<int> node0("0", 1);
  CXXGraph::Node<int> node1("1", 1);
  CXXGraph::Node<int> node2("2", 1);
  CXXGraph::Node<int> node3("3", 1);
  CXXGraph::Node<int> node4("4", 1);
  CXXGraph::Node<int> node5("5", 1);
  CXXGraph::Node<int> node6("6", 1);

  CXXGraph::UndirectedWeightedEdge<int> edge1(1, node0, node1, 2);
  CXXGraph::UndirectedWeightedEdge<int> edge2(2, node0, node2, 6);
  CXXGraph::UndirectedWeightedEdge<int> edge3(3, node1, node3, 5);
  CXXGraph::UndirectedWeightedEdge<int> edge4(4, node2, node3, 8);
  CXXGraph::UndirectedWeightedEdge<int> edge5(5, node3, node5, 15);
  CXXGraph::UndirectedWeightedEdge<int> edge6(6, node3, node4, 10);
  CXXGraph::UndirectedWeightedEdge<int> edge7(7, node4, node5, 6);
  CXXGraph::UndirectedWeightedEdge<int> edge8(8, node4, node6, 2);
  CXXGraph::UndirectedWeightedEdge<int> edge9(9, node5, node6, 6);

  CXXGraph::T_EdgeSet<int> edgeSet;
  edgeSet.insert(&edge1);
  edgeSet.insert(&edge2);
  edgeSet.insert(&edge3);
  edgeSet.insert(&edge4);
  edgeSet.insert(&edge5);
  edgeSet.insert(&edge6);
  edgeSet.insert(&edge7);
  edgeSet.insert(&edge8);
  edgeSet.insert(&edge9);

  CXXGraph::Graph<int> graph(edgeSet);
  CXXGraph::DijkstraResult res = graph.dijkstra(node0, node1);
  ASSERT_TRUE(res.success);
  ASSERT_EQ(res.errorMessage, "");
  ASSERT_EQ(res.result, 2);
  res = graph.dijkstra(node0, node2);
  ASSERT_TRUE(res.success);
  ASSERT_EQ(res.errorMessage, "");
  ASSERT_EQ(res.result, 6);
  res = graph.dijkstra(node0, node3);
  ASSERT_TRUE(res.success);
  ASSERT_EQ(res.errorMessage, "");
  ASSERT_EQ(res.result, 7);
  res = graph.dijkstra(node0, node4);
  ASSERT_TRUE(res.success);
  ASSERT_EQ(res.errorMessage, "");
  ASSERT_EQ(res.result, 17);
  res = graph.dijkstra(node0, node5);
  ASSERT_TRUE(res.success);
  ASSERT_EQ(res.errorMessage, "");
  ASSERT_EQ(res.result, 22);
  res = graph.dijkstra(node0, node6);
  ASSERT_TRUE(res.success);
  ASSERT_EQ(res.errorMessage, "");
  ASSERT_EQ(res.result, 19);
}

TEST(DijkstraTest, correct_example_5) {
  // Example from https://es.wikipedia.org/wiki/Algoritmo_de_Dijkstra
  CXXGraph::Node<int> node1("1", 1);
  CXXGraph::Node<int> node2("2", 1);
  CXXGraph::Node<int> node3("3", 1);
  CXXGraph::Node<int> node4("4", 1);
  CXXGraph::Node<int> node5("5", 1);
  CXXGraph::Node<int> node6("6", 1);

  CXXGraph::UndirectedWeightedEdge<int> edge1(1, node1, node2, 7);
  CXXGraph::UndirectedWeightedEdge<int> edge2(2, node1, node3, 9);
  CXXGraph::UndirectedWeightedEdge<int> edge3(3, node1, node6, 14);
  CXXGraph::UndirectedWeightedEdge<int> edge4(4, node2, node4, 15);
  CXXGraph::UndirectedWeightedEdge<int> edge5(5, node2, node3, 10);
  CXXGraph::UndirectedWeightedEdge<int> edge6(6, node3, node4, 11);
  CXXGraph::UndirectedWeightedEdge<int> edge7(7, node3, node6, 2);
  CXXGraph::UndirectedWeightedEdge<int> edge8(8, node4, node5, 6);
  CXXGraph::UndirectedWeightedEdge<int> edge9(9, node6, node5, 9);

  CXXGraph::T_EdgeSet<int> edgeSet;
  edgeSet.insert(&edge1);
  edgeSet.insert(&edge2);
  edgeSet.insert(&edge3);
  edgeSet.insert(&edge4);
  edgeSet.insert(&edge5);
  edgeSet.insert(&edge6);
  edgeSet.insert(&edge7);
  edgeSet.insert(&edge8);
  edgeSet.insert(&edge9);

  CXXGraph::Graph<int> graph(edgeSet);
  CXXGraph::DijkstraResult res = graph.dijkstra(node1, node5);
  ASSERT_TRUE(res.success);
  ASSERT_EQ(res.errorMessage, "");
  ASSERT_EQ(res.result, 20);
}

TEST(DijkstraTest, non_weigthed_node_test) {
  CXXGraph::Node<int> node1("1", 1);
  CXXGraph::Node<int> node2("2", 2);
  CXXGraph::Node<int> node3("3", 3);

  std::pair<const CXXGraph::Node<int> *, const CXXGraph::Node<int> *> pairNode(
      &node1, &node2);
  CXXGraph::DirectedWeightedEdge<int> edge1(1, pairNode, 5);
  CXXGraph::DirectedEdge<int> edge2(2, node2, node3);
  CXXGraph::UndirectedWeightedEdge<int> edge3(3, node1, node3, 6);

  CXXGraph::T_EdgeSet<int> edgeSet;
  edgeSet.insert(&edge1);
  edgeSet.insert(&edge2);
  edgeSet.insert(&edge3);

  CXXGraph::Graph<int> graph(edgeSet);
  CXXGraph::DijkstraResult res = graph.dijkstra(node1, node3);
  ASSERT_FALSE(res.success);
  ASSERT_EQ(res.errorMessage, CXXGraph::ERR_NO_WEIGHTED_EDGE);
  ASSERT_EQ(res.result, CXXGraph::INF_DOUBLE);
}

TEST(DijkstraTest, negative_weigthed_node_test) {
  CXXGraph::Node<int> node1("1", 1);
  CXXGraph::Node<int> node2("2", 2);
  CXXGraph::Node<int> node3("3", 3);

  std::pair<const CXXGraph::Node<int> *, const CXXGraph::Node<int> *> pairNode(
      &node1, &node2);
  CXXGraph::DirectedWeightedEdge<int> edge1(1, pairNode, -5);
  CXXGraph::DirectedWeightedEdge<int> edge2(2, node2, node3, 5);
  CXXGraph::UndirectedWeightedEdge<int> edge3(3, node1, node3, 6);

  CXXGraph::T_EdgeSet<int> edgeSet;
  edgeSet.insert(&edge1);
  edgeSet.insert(&edge2);
  edgeSet.insert(&edge3);

  CXXGraph::Graph<int> graph(edgeSet);
  CXXGraph::DijkstraResult res = graph.dijkstra(node1, node3);
  ASSERT_FALSE(res.success);
  ASSERT_EQ(res.errorMessage, CXXGraph::ERR_NEGATIVE_WEIGHTED_EDGE);
  ASSERT_EQ(res.result, CXXGraph::INF_DOUBLE);
}

TEST(DijkstraTest, unreachable_node_test) {
  CXXGraph::Node<int> node1("1", 1);
  CXXGraph::Node<int> node2("2", 2);
  CXXGraph::Node<int> node3("3", 3);

  CXXGraph::DirectedEdge<int> edge2(2, node2, node3);
  CXXGraph::UndirectedWeightedEdge<int> edge3(3, node1, node3, 6);

  CXXGraph::T_EdgeSet<int> edgeSet;
  edgeSet.insert(&edge2);
  edgeSet.insert(&edge3);

  CXXGraph::Graph<int> graph(edgeSet);
  CXXGraph::DijkstraResult res = graph.dijkstra(node1, node2);
  ASSERT_FALSE(res.success);
  ASSERT_EQ(res.errorMessage, CXXGraph::ERR_TARGET_NODE_NOT_REACHABLE);
  ASSERT_EQ(res.result, CXXGraph::INF_DOUBLE);
}

TEST(DijkstraTest, source_not_connected_test) {
  CXXGraph::Node<int> node1("1", 1);
  CXXGraph::Node<int> node2("2", 2);
  CXXGraph::Node<int> node3("3", 3);
  CXXGraph::Node<int> node4("4", 4);

  CXXGraph::DirectedEdge<int> edge2(2, node2, node3);
  CXXGraph::UndirectedWeightedEdge<int> edge3(3, node1, node3, 6);

  CXXGraph::T_EdgeSet<int> edgeSet;
  edgeSet.insert(&edge2);
  edgeSet.insert(&edge3);

  CXXGraph::Graph<int> graph(edgeSet);
  CXXGraph::DijkstraResult res = graph.dijkstra(node4, node2);
  ASSERT_FALSE(res.success);
  ASSERT_EQ(res.errorMessage, CXXGraph::ERR_SOURCE_NODE_NOT_IN_GRAPH);
  ASSERT_EQ(res.result, CXXGraph::INF_DOUBLE);
}

TEST(DijkstraTest, target_not_connected_test) {
  CXXGraph::Node<int> node1("1", 1);
  CXXGraph::Node<int> node2("2", 2);
  CXXGraph::Node<int> node3("3", 3);
  CXXGraph::Node<int> node4("4", 4);

  CXXGraph::DirectedEdge<int> edge2(2, node2, node3);
  CXXGraph::UndirectedWeightedEdge<int> edge3(3, node1, node3, 6);

  CXXGraph::T_EdgeSet<int> edgeSet;
  edgeSet.insert(&edge2);
  edgeSet.insert(&edge3);

  CXXGraph::Graph<int> graph(edgeSet);
  CXXGraph::DijkstraResult res = graph.dijkstra(node1, node4);
  ASSERT_FALSE(res.success);
  ASSERT_EQ(res.errorMessage, CXXGraph::ERR_TARGET_NODE_NOT_IN_GRAPH);
  ASSERT_EQ(res.result, CXXGraph::INF_DOUBLE);
}