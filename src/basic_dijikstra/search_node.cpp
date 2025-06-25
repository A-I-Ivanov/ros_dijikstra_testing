#include "basic_dijikstra/search_node.h"

SearchNode::SearchNode(int x, int y)
{
  idx_.x_idx = x;
  idx_.y_idx = y;
}

// Setters
void SearchNode::SetCTG(double cost)
{
  cost_to_go_ = cost;
}

void SearchNode::SetCTC(double cost, NodePtr parent)
{
  cost_to_come_ = cost;
  parent_ = parent;
}

// Getters
double SearchNode::CTG()
{
  return cost_to_go_;
}

SearchNode::NodePtr SearchNode::Parent()
{
  return parent_;
}

const NodeIdx& SearchNode::Idx()
{
  return idx_;
}
