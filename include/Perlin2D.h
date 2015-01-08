#ifndef PERLIN2D_HPP
#define PERLIN2D_HPP
#include <iostream>
#include <Tile.h>
#include <Map.h>



#define OFFSET 3
#define SIZE MAP_WIDTH
#define WIDTH SIZE
#define HEIGHT WIDTH

//COLOR
//#define COLORED
#define DEEP_SEA 10
#define SEA 50
#define SAND 70
#define GROUND 200

class Perlin2D
{
public:
Perlin2D();
~Perlin2D();

void init();
void initValue();
void initValueRandom();
void initValueCenterMountain();
void initInterpolations();
double linear_interpolation(double a,double b, double t);
double polynomial_interpolation(double a,double b, double t);
double interpolation(double a,double b, double t);

void display();

static double random(int a,int b);
static double random();
  
bool inMap(int i,int j){ return (i >= 0 && i<WIDTH && j >=0 && j<HEIGHT);}
void operator()()
{
display();
}

double get(int i,int j)const ;

private:
double m_tab[HEIGHT][WIDTH];
};

#endif
