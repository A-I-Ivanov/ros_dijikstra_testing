#include "basic_dijikstra/basic_dijikstra.h"

#include <cmath>

///////////////////////////////////////////////////////////////////////////////
BasicDijikstra::BasicDijikstra(std::shared_ptr<Lattice> lattice,
                               double x_pitch, double y_pitch)
{
  path_.push_back(State());
  lattice_ = lattice;
  x_size_ = lattice->size();
  y_size_ = (*lattice)[0].size();
  x_pitch_ = x_pitch;
  y_pitch_ = y_pitch;
}

///////////////////////////////////////////////////////////////////////////////
bool BasicDijikstra::SetStart(State start)
{
  if (!(start == start))
  {
    ResetCTC();
    return false;
  }
  return true;
}

///////////////////////////////////////////////////////////////////////////////
bool BasicDijikstra::SetGoal(State goal)
{
  NodePtr new_node = GetNearest(goal);
  if (!(new_node == goal_node_))
  {
    ResetCTG();
    return false;
  }

  goal_node_ = new_node;
  // Goal has 0 cost to go
  goal_node_->SetCTG(0);
  return true;
}

///////////////////////////////////////////////////////////////////////////////
bool BasicDijikstra::DoSearch()
{
  // Todo implement this
  queue_.push(GetNearest(start_));
  // Start has 0 cost to come
  queue_.top()->SetCTC(0, nullptr);

  // Add equality operator to node, this comparision may be wrong
  while (!(queue_.empty()) && !(goal_node_->Parent()))
  {
    auto candidate = queue_.top();
    queue_.pop();

    std::vector<double> costs;
    std::vector<NodePtr> neighbours = GetNeighbors(candidate, costs);

    for (size_t ii = 0; ii < neighbours.size(); ii++)
    {
      double new_cost = candidate->CTC() + costs[ii];
      if (new_cost < neighbours[ii]->CTC())
      {
        neighbours[ii]->SetCTC(new_cost, candidate);
        queue_.push(neighbours[ii]);
      }
    }

    if (goal_node_->Parent())
    {
      return true;
    }

    return false;
  }

  return false;
}

///////////////////////////////////////////////////////////////////////////////
std::vector<BasicDijikstra::NodePtr>
BasicDijikstra::GetNeighbors(NodePtr node, std::vector<double>& costs)
{
  std::vector<NodePtr> neighbours;
  auto index = node->Idx();
  // comment For now we simply do 8 connected neighbours. This is +-1
  // (x_idx,y_idx)

  // Helper lambda to prevent repeated code
  auto add_y_nodes = [&](size_t x_idx) {
    if (index.y_idx < (*lattice_)[0].size() - 1)
    {
      neighbours.push_back(std::make_shared<SearchNode>(
          (*lattice_)[x_idx][index.y_idx + 1]));
    }
    if (index.y_idx > 0)
    {
      neighbours.push_back(std::make_shared<SearchNode>(
          (*lattice_)[x_idx][index.y_idx - 1]));
    }
  };

  // Add constant x
  add_y_nodes(index.x_idx);

  if (index.x_idx < lattice_->size() - 1)
  {
    neighbours.push_back(std::make_shared<SearchNode>(
        (*lattice_)[index.x_idx + 1][index.y_idx]));
    add_y_nodes(index.x_idx + 1);
  }
  if (index.x_idx > 0)
  {
    neighbours.push_back(std::make_shared<SearchNode>(
        (*lattice_)[index.x_idx - 1][index.y_idx]));
    add_y_nodes(index.x_idx - 1);
  }

  // TODO need to figure out how to make better cost structure this is
  // wrong
  costs.clear();
  for (auto neighbour : neighbours)
  {
    costs.push_back(1.0);
  }
  return neighbours;
}

///////////////////////////////////////////////////////////////////////////////
BasicDijikstra::NodePtr BasicDijikstra::GetNearest(State query)
{
  double x_idx_;
  double y_idx_;

  double x_remain = std::modf(query.x_pos / x_pitch_, &x_idx_);
  double y_remain = std::modf(query.y_pos / y_pitch_, &y_idx_);

  if (x_remain > 0.5)
  {
    x_idx_++;
  }
  if (y_remain > 0.5)
  {
    y_idx_++;
  }

  return std::make_shared<SearchNode>(
      (*lattice_)[(int)x_idx_][(int)y_idx_]);
}

///////////////////////////////////////////////////////////////////////////////
void BasicDijikstra::ResetCTC()
{
  for (auto& node_row : (*lattice_))
  {
    for (auto& node : node_row)
    {
      node.SetCTC(std::numeric_limits<double>::infinity(), nullptr);
    }
  }
}

///////////////////////////////////////////////////////////////////////////////
void BasicDijikstra::ResetCTG()
{
  for (auto& node_row : (*lattice_))
  {
    for (auto& node : node_row)
    {
      node.SetCTG(std::numeric_limits<double>::infinity());
    }
  }
}
