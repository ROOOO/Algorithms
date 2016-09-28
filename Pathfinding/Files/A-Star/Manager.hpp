#ifndef __MANAGER_HPP__
#define __MANAGER_HPP__

#include <list>
#include <algorithm>
#include "Point.hpp"
#include <vector>

class Point;
const int STEP = 10;
const int OBLIQUE = 14;
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
  std::vector<std::vector<int>> m_map;

public:
  Mgr(std::vector<std::vector<int>> map);
  Point * FindPath(Point *start, Point *end);
  void PrintPath(Point *e);
};
#endif
