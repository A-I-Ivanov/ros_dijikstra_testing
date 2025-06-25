#pragma once

#include <memory>
#include <queue>
#include <vector>

#include "search_node.h"

/////////////////////////////////////////////////////////////////////////////////////////
struct State
{
  double x_pos = 0;
  double y_pos = 0;
  double angle = 0;
  friend bool operator==(const State& l, const State& r) noexcept
  {
    return (l.x_pos == r.x_pos) && (l.y_pos == r.y_pos) &&
           (l.angle == r.angle);
  }
};

/////////////////////////////////////////////////////////////////////////////////////////
class BasicDijikstra
{
public:
  using Path = std::vector<State>;
  using Lattice = std::vector<std::vector<SearchNode>>;
  using NodePtr = std::shared_ptr<SearchNode>;

  BasicDijikstra(std::shared_ptr<Lattice> lattice, double x_pitch,
                 double y_pitch);

  /// @brief Start state setter
  /// @param start Start state to plan from
  /// @return True if the start pose was the same as the previous
  /// start.
  bool SetStart(State start);

  /// @brief Goal state setter
  /// @param goal Goal to plan to
  /// @return True iff the goal is the same as the last goal planned
  /// to
  bool SetGoal(State goal);

  /// @brief Perform the actual path search.
  /// @return True iff the search is successful
  bool DoSearch();

  /// @brief Get the nearest lattice point in x,y to the query state
  /// @param query The statet to evaluate
  /// @return The node closes in xy to the query
  NodePtr GetNearest(State query);

  /// @brief Get the neighbours of the given node.
  /// @param node The query node
  /// @param costs[out] The edge cost to each neighbour
  /// @return A vector of node pointers
  std::vector<NodePtr> GetNeighbors(NodePtr node,
                                    std::vector<double>& costs);

private:
  Path path_ = Path();
  void ResetCTG();
  void ResetCTC();

  // This comparator is wrong, fix it.
  std::priority_queue<NodePtr, std::vector<NodePtr>,
                      std::greater<NodePtr>>
      queue_;
  std::shared_ptr<Lattice> lattice_;
  State start_ = State();
  NodePtr goal_node_;
  size_t x_size_ = 0;
  size_t y_size_ = 0;
  double x_pitch_ = 0;
  double y_pitch_ = 0;
};
