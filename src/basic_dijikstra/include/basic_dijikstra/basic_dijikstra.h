#include <vector>
#include <memory>
#include <queue>
#include "search_node.h"

struct State{
  double x_pos = 0;
  double y_pos = 0;
  double angle = 0;
  friend bool operator==(const State& l, const State& r) noexcept{
    return (l.x_pos==r.x_pos) && (l.y_pos==r.y_pos)&& (l.angle==r.angle);
  }
};


class BasicDijikstra {
public:
  using Path = std::vector<State>;
  using Lattice = std::vector<std::vector<SearchNode>>;
  using NodePtr = std::shared_ptr<SearchNode>;

  BasicDijikstra(std::shared_ptr<Lattice> lattice, double x_pitch, double y_pitch);

  bool SetStart(State start);
  bool SetGoal(State goal);
  bool DoSearch();
  NodePtr GetNearest(State query);
  std::vector<NodePtr> GetNeighbors(NodePtr node);

private:
  Path path_ = Path();
  std::priority_queue<NodePtr> queue_; 
  std::shared_ptr<Lattice> lattice_;
  State start_ = State();
  State goal_ = State();
  size_t x_size_ = 0;
  size_t y_size_ = 0;
  double x_pitch_ =0;
  double y_pitch_ =0;

};
