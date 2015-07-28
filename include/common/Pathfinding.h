#ifndef PATHFINDING_H
#define PATHFINDING_H
#define MAX_WEIGHT 1000
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

namespace lae3
{
  namespace common
  {
    
    class Map;
    
    enum TileType
    {
      GROUND=0,
      WALL=1,
      WATER=2
    };

    struct Node
    {
      int i;
      int j;
      unsigned weight;
      std::shared_ptr<Node> father;

      Node(int _i, int _j)
      {
      	i = _i;
      	j = _j;

	father = nullptr;
	weight = MAX_WEIGHT;
      }
      
    };
    
    class Pathfinding
    {
    public:

      Pathfinding(Map &m);
      virtual ~Pathfinding();
      
      bool compute(int i1, int j1, int i2, int j2);
      
    protected:
      Map &m_map;
    private:
      Pathfinding( Pathfinding const& pathfinding ) = delete;
      Pathfinding& operator=( Pathfinding const& pathfinding ) = delete;
  
      std::vector< std::shared_ptr<Node> > m_close;
      std::vector< std::shared_ptr<Node> > m_open;
      
      std::vector< std::shared_ptr<Node> > m_nodes;
      
    };
  }
}
#endif
