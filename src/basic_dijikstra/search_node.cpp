#include "basic_dijikstra/search_node.h"


SearchNode::SearchNode(int x, int y)
{
        x_idx_ = x;
        y_idx_ = y;

}
// Setters
void SearchNode::SetNeighbours(std::vector<NodePtr> neighbors){
        neighbors_ = std::move(neighbors);
}

void SearchNode::SetCTG(double cost){
 cost_to_go_ = cost;
}

//Getters
double SearchNode::GetCTG(){
 return cost_to_go_;
}

SearchNode::NodePtr SearchNode::GetParent(){
 return parent_;
}


  
