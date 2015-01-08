#include <Perlin2D.h>
#include <cstdlib>
#include <cmath>

Perlin2D::Perlin2D()
{
  init();
  initValue();
  initInterpolations();
}

void Perlin2D::init()
{
  for(int i=0;i<HEIGHT;i++)
    {
      for(int j=0;j<WIDTH;j++)
	{
	  m_tab[i][j] = -1;
	}
    }
}

void Perlin2D::initValueCenterMountain()
{
  int  a= WIDTH/10;
  for(int i=0;i<HEIGHT;i+=OFFSET)
    {
      for(int j=0;j<WIDTH;j+=OFFSET)
	{

	  if(i > a && i < HEIGHT - a
	     && j > a && j < WIDTH - a)
	    {
	      m_tab[i][j] =  Perlin2D::random(GROUND-40,256);
	    }
	  else
	    {
	      m_tab[i][j] = Perlin2D::random(50,100);	  
	    }
	}
    }

}

void Perlin2D::initValueRandom()
{
  for(int i=0;i<HEIGHT;i+=OFFSET)
    {
      for(int j=0;j<WIDTH;j+=OFFSET)
	{
	      m_tab[i][j] = Perlin2D::random(0,256);	  
	}
    }

}

void Perlin2D::initValue()
{
  initValueCenterMountain();
}

double Perlin2D::get(int i,int j)const 
{
  return m_tab[i][j];
}



void Perlin2D::initInterpolations()
{
  
  int Ai = 0;
  int Aj = 0;

  int Bi,Bj,Ci,Cj,Di,Dj,Ei,Ej,Fi,Fj;

  double ratioEAB = 0.0;
  double ratioFDC = 0.0;
  double ratioMEF = 0.0;
  int a =1;
  for(int i=0;i< HEIGHT;i++)
    {
      for(int j=0;j< WIDTH;j++)
	{
	  
	  if(i%OFFSET != 0 || j%OFFSET != 0)
	    { 
	      
	      if( m_tab[i][j] == -1)
		//	if(i==8 && j==4 )
		{
		  
		  Ai = OFFSET*(i/OFFSET);
		  Aj = OFFSET*(j/OFFSET);
		  
		  Bi = Ai;
		  Bj = Aj + OFFSET;
		  Ci = Ai + OFFSET;
		  Cj = Aj + OFFSET;
		  Di = Ai + OFFSET;
		  Dj = Aj;


		  Ei = Ai;
		  Ej = j;

		  Fi = Di;
		  Fj = j;
		  
		  ratioEAB = -1;
		  ratioFDC = -1;

		  if(inMap(Ei,Ej))
		    {
		      ratioEAB = 
			static_cast<double>(Ej-Aj)/static_cast<double>(OFFSET);

		      m_tab[Ei][Ej] = 
			interpolation(m_tab[Ai][Aj],m_tab[Bi][Bj],ratioEAB);
		    }
		  
		  if(inMap(Fi,Fj))
		    {
		      ratioFDC = 
			static_cast<double>(Fj-Dj)/static_cast<double>(OFFSET);

		      if(Fj-Dj<0)std::cout<<i<<" "<<j<<std::endl;
		      m_tab[Fi][Fj] = 
			interpolation(m_tab[Di][Dj],m_tab[Ci][Cj],ratioFDC);
		    }
		  
		  
		  ratioMEF = 
		    static_cast<double>(i-Ei)/static_cast<double>(OFFSET);

		
		  if( inMap(Ei,Ej) && inMap(Fi,Fj) )
		    {
		      m_tab[i][j] = 
			interpolation(m_tab[Ei][Ej],m_tab[Fi][Fj],ratioMEF);
		    }
		    //else m_tab[i][j] = 0;


		}


	    }

	  
	}
    }
}

double Perlin2D::interpolation(double a,double b, double t)
{

  return polynomial_interpolation(a,b,t);
}

double Perlin2D::polynomial_interpolation(double a,double b, double t)
{
  double u = (1-cos(t*M_PI))*0.5;

  return linear_interpolation(a,b,u);
}

double Perlin2D::linear_interpolation(double a,double b, double t)
{
  return a*(1-t) + b*(t);
}

double Perlin2D::random(int a,int b)
{
  return static_cast<double>(rand()%(b-a)+a);
}

double Perlin2D::random()
{
  return static_cast<double>(Perlin2D::random(0,1000))/1000.0;
}

void Perlin2D::display()
{
    for(int i=0;i<HEIGHT;i++)
    {
      for(int j=0;j<WIDTH;j++)
	{
	  std::cout<<m_tab[i][j]<<"   ";
	}std::cout<<'\n';
    }
}

Perlin2D::~Perlin2D()
{



}
