#include "basic_dijikstra/basic_dijikstra.h"

#include <gtest/gtest.h>

#include "basic_dijikstra/search_node.h"

TEST(search_node, construction)
{
  SearchNode node(1, 2);
  ASSERT_EQ(node.Idx().x_idx, 1);
  ASSERT_EQ(node.Idx().y_idx, 2);

  node = SearchNode(3, 4);

  ASSERT_EQ(node.Idx().x_idx, 3);
  ASSERT_EQ(node.Idx().y_idx, 4);
}

int main(int argc, char** argv)
{
  testing::InitGoogleTest(&argc, argv);
  std::cout << "Got to main";
  return RUN_ALL_TESTS();
}
