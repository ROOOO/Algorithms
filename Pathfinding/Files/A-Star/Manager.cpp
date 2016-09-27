#include "Manager.hpp"
#include <iostream>

Mgr::Mgr() {
}
bool Mgr::m_Exists(std::list<Point*>* points, int x, int y) const {
  for (auto pi = points->begin(); pi != points->end(); ++pi) {
    if ((*pi)->X == x && (*pi)->Y == y) {
      return true;
    }
  }
  return false;
}

Point* Mgr::m_Get(std::list<Point*>* points, Point* p) {
  int x = p->X, y = p->Y;
  for (auto pi = points->begin(); pi != points->end(); ++pi) {
    if ((*pi)->X == x && (*pi)->Y == y) {
      return p;
    }
  }
  return nullptr;
}

Point* Mgr::GetMinFPoint() {
  std::list<Point*>::value_type p = nullptr;
  for (auto pi = this->m_openList->begin(); pi != this->m_openList->end(); ++pi) {
    if (!p) {
      p = *pi;
      continue;
    }
    if ((*pi)->F < p->F) {
      p = *pi;
    }
  }
  return p;
}

void Mgr::PrintPath(Point *e) {
  auto parent = e->parent;
  std::cout << e->X << "," << e->Y << std::endl;
  while (parent) {
    std::cout << parent->X << "," << parent->Y << std::endl;
    parent = parent->parent;
  }
}

Point * Mgr::FindPath(Point *start, Point *end) {
  this->m_openList->push_back(start);

  while (this->m_openList->size() != 0) {
    Point *minFPoint = this->GetMinFPoint();
    this->m_openList->pop_front();
    if (minFPoint == nullptr) {
      continue;
    }

    this->m_clostList->push_back(minFPoint);
    auto surroundPoints = this->FindSurrounded(minFPoint);
    if (surroundPoints) {
      for (auto sp = surroundPoints->begin(); sp != surroundPoints->end(); ++sp) {
        if (this->m_Exists(this->m_openList, (*sp)->X, (*sp)->Y)) {
          FoundInOpenList(minFPoint, *sp);
        }
        else {
          this->NotFoundInOpenList(minFPoint, end, *sp);
        }
      }
    }

    auto endPoint = this->m_Get(this->m_openList, end);
    if (endPoint) {
      endPoint->SetParent(minFPoint);
      return endPoint;
    }
  }
  
  return this->m_Get(this->m_openList, end);
}
void Mgr::FoundInOpenList(Point* center, Point* point) {
  auto G = this->CalcG(center, point);
  if (G < point->G) {
    point->SetParent(center);
    point->G = G;
    point->F = this->CalcF(point);
  }
}
void Mgr::NotFoundInOpenList(Point* center, Point *end, Point* point) {
  point->SetParent(center);
  point->G = this->CalcG(center, point);
  point->H = this->CalcH(end, point);
  point->F = this->CalcF(point);
  this->m_openList->push_back(point);
}

bool Mgr::CanReach(int x, int y) {
  if (MAP[x][y] != 0 || this->m_Exists(this->m_clostList, x, y)) {
    return false;
  }
  return true;
}

std::list<Point*>* Mgr::FindSurrounded(Point* point) {
  std::list<Point *> *surrounded = new std::list<Point*>;
  for (int x = -1; x <= 1; x++) {
    for (int y = -1; y <= 1; y++) {
      if (this->CanReach(point->X + x, point->Y + y)) {
        Point* tempP = new Point(point->X + x, point->Y + y);
        surrounded->push_back(tempP);
      }
    }
  }
  return surrounded;
}


int Mgr::CalcF(Point *p) {
  return p->G + p->H;
}
int Mgr::CalcG(Point* parent, Point *p) {
  int G = (abs(p->X - parent->X) + abs(p->Y - parent->Y)) != 2 ? STEP : OBLIQUE;
  int parentG = parent->parent == nullptr ? 0 : parent->parent->G;
  return G + parentG;
}
int Mgr::CalcH(Point* end, Point *p) {
  return (abs(p->X - end->X) + abs(p->Y - end->Y)) * STEP;
}

