#include "Manager.hpp"
#include <iostream>

#define test 1
int main() {
#if test == 1
  Point start(3, 2);
  Point end(3, 6);
  const std::vector<std::vector<int>> MAP = {
    { 1, 1, 1, 1, 1, 1, 1, 1, 1 },
    { 1, 0, 0, 0, 0, 0, 0, 0, 1 },
    { 1, 0, 0, 0, 1, 0, 0, 0, 1 },
    { 1, 0, 0, 0, 1, 0, 0, 0, 1 },
    { 1, 0, 0, 0, 1, 0, 0, 0, 1 },
    { 1, 0, 0, 0, 0, 0, 0, 0, 1 },
    { 1, 1, 1, 1, 1, 1, 1, 1, 1 }
  };
#elif test == 2
  Point start(1, 1);
  Point end(6, 10);
  const std::vector<std::vector<int>> MAP = {
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
  Mgr mgr(MAP);
  Point* e = mgr.FindPath(&start, &end);
  mgr.PrintPath(e);
  getchar();
}