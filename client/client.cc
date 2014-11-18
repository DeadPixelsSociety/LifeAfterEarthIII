#include <iostream>
#include "Map.h"
using namespace std;

int main(int argc, char *argv[])
{
  
  client::Map m;
  m.generateWall(0.3);
  m.display();

  
  
  
}
