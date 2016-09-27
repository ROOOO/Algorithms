#include "Point.hpp"

Point::Point(int x, int y) : X(x), Y(y) {
  this->F = 0;
  this->G = 0;
  this->H = 0;
}
Point::~Point() {
  this->X = 0;
  this->Y = 0;
  this->F = 0;
  this->G = 0;
  this->H = 0;
  this->parent = nullptr;
}

void Point::SetParent(Point *parent) {
  this->parent = parent;
}
