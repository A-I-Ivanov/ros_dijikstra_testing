# include <queue>
#include <memory>
#include <limits>

class SearchNode{
        using NodePtr= std::shared_ptr<SearchNode>;
  public:
        SearchNode(int x, int y);
        // Setters
        void SetNeighbours(std::vector<NodePtr> neighbors);
        void SetCTG(double cost);
        
        //Getters
        double GetCTG();
        NodePtr GetParent();

        friend bool operator<(const SearchNode& l, const SearchNode& r){
                return l.cost_to_go_<r.cost_to_go_;
        }  

  
  private: 
        double cost_to_go_ = std::numeric_limits<double>::infinity();
        int x_idx_;
        int y_idx_;
        NodePtr parent_;
        std::vector<NodePtr> neighbors_; 
};