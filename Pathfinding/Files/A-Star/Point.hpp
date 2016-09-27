#ifndef __POINT_HPP__
#define __POINT_HPP__

#include <list>
#include "Manager.hpp"

class Mgr;
class Point {
public:
  Point(int x = 0, int y = 0);
  ~Point();
  int F = 0, G = 0, H = 0;
  int X = 0, Y = 0;
  Point *parent = nullptr;
  void SetParent(Point *p);
};
#endif
