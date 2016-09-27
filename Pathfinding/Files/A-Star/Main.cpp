#include "Manager.hpp"
#include <iostream>


void main() {
#if test == 1
  Point start(3, 2);
  Point end(3, 6);
#elif test == 2
  Point start(1, 1);
  Point end(6, 10);
#endif

  Mgr mgr;
  Point* e = mgr.FindPath(&start, &end);
  mgr.PrintPath(e);
  getchar();
}