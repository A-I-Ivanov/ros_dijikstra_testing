#pragma once

#include <limits>
#include <memory>
#include <queue>

struct NodeIdx
{
  size_t x_idx = 0;
  size_t y_idx = 0;
};

class SearchNode
{
public:
  using NodePtr = std::shared_ptr<SearchNode>;

  SearchNode(int x, int y);
  // Setters
  void SetCTG(double cost_to_go);
  void SetCTC(double cost_to_come, NodePtr parent);

  // Getters
  double CTG();
  double CTC();
  NodePtr Parent();
  const NodeIdx& Idx();

private:
  double cost_to_go_ = std::numeric_limits<double>::infinity();
  double cost_to_come_ = std::numeric_limits<double>::infinity();
  NodeIdx idx_;
  NodePtr parent_;
};
