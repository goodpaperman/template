// dynapoly.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <math.h>
#include <vector> 
using std::vector; 

class Coord
{
public:
  Coord(int x, int y) : x_(x), y_(y) {}
  int x() const { return x_; } 
  int y() const { return y_; } 
  Coord abs() const { return Coord(::abs(x_), ::abs(y_)); } 
  friend Coord operator- (Coord const&, Coord const&); 
  friend Coord operator+ (Coord const&, Coord const&); 

private:
  int x_, y_; 
}; 

Coord operator- (Coord const& a, Coord const& b)
{
  return Coord(a.x_ - b.x_, a.y_ - b.y_); 
}

Coord operator+ (Coord const& a, Coord const& b)
{
  return Coord(a.x_ + b.x_, a.y_ + b.y_); 
}


class GeoObj
{
public:
  virtual void draw() const = 0; 
  virtual Coord center_of_gravity() const = 0; 
}; 

class Circle : public GeoObj
{
public:
  virtual void draw() const 
  { printf("Circle::draw\n"); }
  virtual Coord center_of_gravity() const
  { printf("Circle::center_of_gravity\n"); return Coord(42, 24); } 
}; 

class Line : public GeoObj
{
public:
  virtual void draw() const 
  { printf("Line::draw\n"); }
  virtual Coord center_of_gravity() const
  { printf("Line::center_of_gravity\n"); return Coord(101, 58); } 
}; 

void myDraw(GeoObj const& obj)
{
  obj.draw(); 
}

Coord distance(GeoObj const& x1, GeoObj const& x2)
{
  Coord c = x1.center_of_gravity() - x2.center_of_gravity(); 
  return c.abs(); 
}

void drawElems(vector<GeoObj*> const& elems)
{
  for(unsigned i=0; i<elems.size(); ++ i)
    elems[i]->draw(); 
}

int _tmain(int argc, _TCHAR* argv[])
{
  Line l; 
  Circle c, c1, c2; 

  myDraw(l); 
  myDraw(c); 
  Coord coo = distance(c1, c2); 
  printf("coord = %d, %d\n", coo.x(), coo.y()); 
  coo = distance(l, c); 
  printf("coord = %d, %d\n", coo.x(), coo.y()); 

  vector<GeoObj*> coll; 
  coll.push_back(&l); 
  coll.push_back(&c); 
  drawElems(coll); 
	return 0;
}

