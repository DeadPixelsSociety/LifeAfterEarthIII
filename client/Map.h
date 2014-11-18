#ifndef MAP_H
#define MAP_H
#define WIDTH 10
#define HEIGHT 10
#include <iostream>


namespace client
{
  enum
  {
    GROUND,
    WALL
  };
  
  class Map
  {

  public:
    Map();
    ~Map();
    
    void init();
    int getTab(int i ,int j){return m_tab[i][j];}
    int setTab(int n,int i,int j){m_tab[i][j] = n;}
    void generateWall(float p);
    void display();


  private:
    
  int m_tab[HEIGHT][WIDTH];
  protected:
  };
  
}
  




#endif
