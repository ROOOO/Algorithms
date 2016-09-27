#ifndef __MANAGER_HPP__
#define __MANAGER_HPP__

#include <list>
#include <algorithm>
#include "Point.hpp"
#include <vector>

#define test 2
class Point;
const int STEP = 10;
const int OBLIQUE = 14;
#if test == 1
const int MAP[8][12] = {
  { 1, 1, 1, 1, 1, 1, 1, 1, 1 },
  { 1, 0, 0, 0, 0, 0, 0, 0, 1 },
  { 1, 0, 0, 0, 1, 0, 0, 0, 1 },
  { 1, 0, 0, 0, 1, 0, 0, 0, 1 },
  { 1, 0, 0, 0, 1, 0, 0, 0, 1 },
  { 1, 0, 0, 0, 0, 0, 0, 0, 1 },
  { 1, 1, 1, 1, 1, 1, 1, 1, 1 }
};
#elif test == 2
const int MAP[8][12] = {
  { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
  { 1, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 1 },
  { 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1 },
  { 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1 },
  { 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 1 },
  { 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1 },
  { 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
  { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
};
#endif
class Mgr {
  std::list<Point *>* m_openList = new std::list<Point *>();
  std::list<Point *>* m_clostList = new std::list<Point *>();
  bool m_Exists(std::list<Point*>* points, int x, int y) const;
  Point* m_Get(std::list<Point*>* points, Point *p);
  std::list<Point *>* FindSurrounded(Point *point);
  bool CanReach(int x, int y);
  int CalcF(Point *p);
  int CalcG(Point* parent, Point *p);
  int CalcH(Point* end, Point *p);
  Point* GetMinFPoint();
  void FoundInOpenList(Point* center, Point* point);
  void NotFoundInOpenList(Point* center, Point *end, Point* point);

public:
  Mgr();
  Point * FindPath(Point *start, Point *end);
  void PrintPath(Point *e);
};
#endif
