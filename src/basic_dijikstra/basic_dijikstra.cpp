#include "basic_dijikstra/basic_dijikstra.h"
#include <cmath>

BasicDijikstra::BasicDijikstra(std::shared_ptr<Lattice> lattice, double x_pitch, double y_pitch)
{
  path_.push_back(State());
  lattice_ = lattice;
  x_size_ = lattice->size();
  y_size_ = (*lattice)[0].size();
  x_pitch_ = x_pitch;
  y_pitch_ = y_pitch;
}

bool BasicDijikstra::SetStart(State start){
  bool same_start = start==start_;
  start_ = start;
  return same_start;
}

bool BasicDijikstra::SetGoal(State goal){
  bool same_goal = goal==goal_;
  goal_=goal;
  return same_goal;
}

bool BasicDijikstra::DoSearch(){
  //Todo implement this
  return false;
}

std::vector<BasicDijikstra::NodePtr> BasicDijikstra::GetNeighbors(NodePtr node){
   std::vector<NodePtr> neighbours;
  //Todo Implement this
  return neighbours;
}

BasicDijikstra::NodePtr BasicDijikstra::GetNearest(State query){
  double x_idx_; 
  double y_idx_; 

  double x_remain = std::modf(query.x_pos/x_pitch_, &x_idx_);
  double y_remain = std::modf(query.y_pos/y_pitch_, &y_idx_);

  if(x_remain>0.5){
    x_idx_++;
  }
  if(y_remain>0.5){
    y_idx_++;
  }

  return std::make_shared<SearchNode>((*lattice_)[(int)x_idx_][(int)y_idx_]);
}
