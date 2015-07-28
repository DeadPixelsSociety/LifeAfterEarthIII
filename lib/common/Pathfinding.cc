#include <common/Pathfinding.h>
#include <common/Map.h>

namespace lae3
{
  namespace common
  {
    Pathfinding::Pathfinding(Map &m): m_map(m)
    {
      for(int i=0; i<Map::MAP_HEIGHT; i++)
	{
	  for(int j=0; j<Map::MAP_WIDTH; j++)
	    {
	      std::shared_ptr<Node> node = std::make_shared<Node>(i, j);
	      m_nodes.push_back(node);
	    }
	}
    }
    
    bool Pathfinding::compute(int i1, int j1, int i2, int j2)
    {
      std::shared_ptr<Node> start = m_nodes[j1 + i1*Map::MAP_WIDTH];
      std::shared_ptr<Node> end = m_nodes[j2 + i2*Map::MAP_WIDTH];

      // init the current for the first time
      start->weight = 0;
      std::shared_ptr<Node> current = start;
      
      while( true )
	{
	  // is the current node the end ?
	  if( current == end )
	    {
	      return true;
	    }

	  // we don't need the current in the open list anymore
	  m_open.erase(std::remove(m_open.begin(), m_open.end(), current), m_open.end());
	  m_close.push_back(current);
	  
	  // for each neighbors
	  auto neighbors = m_map.neighbors(current->i, current->j);
	  for( std::pair<int, int> node_coord : neighbors )
	    {
	      std::shared_ptr<Node> node = m_nodes[node_coord.second + node_coord.first*Map::MAP_WIDTH];
	      
	      // if he is in the closed list, we ignore him
	      auto itr_close = std::find(m_close.begin(), m_close.end(), node);
	      if( itr_close != m_close.end() ){ continue; }

	      // if he is an obstacle, we ignore him
	      if( m_map.get(node->i, node->j) == WALL ){ continue; }
	      
	      // if he is in the open list and if the path from here is better
	      // we update him
	      auto itr_open = std::find(m_open.begin(), m_open.end(), node);
	      unsigned cost = current->weight + m_map.get(node->i, node->j) + m_map.distance(node->i, node->j, end->i, end->j);
	      
	      if( itr_open != m_open.end() )
		{
		  if( (*itr_open)->weight  > cost )
		    {
		      (*itr_open)->father = current;
		      (*itr_open)->weight = cost;
		    }
	 	}
	      // added for the first time
	      else
		{
		  node->father = current;
		  node->weight = cost;
		  m_open.push_back(node);
		}
	      
	    }

	  // if the open list is empty, there is no solution
	  if( m_open.empty() )
	    {
	      std::cerr<< "No path found, regenerating the map" <<std::endl;
	      return false;
	    }
	  
	  // find the next in the open list
	  auto itr_min = std::min_element(m_open.begin(), m_open.end(), [](std::shared_ptr<Node> n1, std::shared_ptr<Node> n2){
	      return n1->weight < n2->weight;
	    });
	  
	  current = *itr_min;
	}
      
      return true;
    }

    Pathfinding::~Pathfinding()
    {
  
    }
  }
}
