# include <queue>
#include <memory>
#include <limits>

class SearchNode{
  using NodePtr = std::shared_ptr<SearchNode>;

public:
  SearchNode(int x, int y);
  // Setters
  void SetNeighbours(std::vector<NodePtr> neighbors);
  void SetCTG(double cost_to_go);
  void SetCTC(double cost_to_come, NodePtr parent);

  //Getters
  double CTG();
  double CTC();
  NodePtr Parent();

private:
  void ResetCTG();
  void ResetCTC();

  double cost_to_go_ = std::numeric_limits<double>::infinity();
  double cost_to_come_ = std::numeric_limits<double>::infinity();
  int x_idx_;
  int y_idx_;
  NodePtr parent_;
  std::vector<NodePtr> neighbors_;
};
