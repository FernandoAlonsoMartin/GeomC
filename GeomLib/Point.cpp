#include "pch.h"
#include "Point.h"

#include <math.h>

Point::Point() : GeomObject() {
  _x = 0.0;
  _y = 0.0;
  _z = 0.0;
}

Point::~Point() {

}

void Point::SetX(const double a_x) {
  _x = a_x;
}

void Point::SetY(const double a_y) {
  _y = a_y;
}

void Point::SetZ(const double a_z) {
  _z = a_z;
}

void Point::SetCoordinates(const double a_x, const double a_y, const double a_z) {
  _x = a_x;
  _y = a_y;
  _z = a_z;
}

double Point::GetX() const {
  return _x;
}

double Point::GetY() const {
  return _y;
}

double Point::GetZ() const {
  return _z;
}

void Point::GetCoordinates(double& a_x, double& a_y, double& a_z) {
  a_x = _x;
  a_y = _y;
  a_z = _z;
}

double Point::Distance(const Point& a_other_point) const {
  return sqrt(pow(a_other_point._x - _x,2.0) + pow(a_other_point._y - _y, 2.0) + pow(a_other_point._z - _z, 2.0));
}

double Point::Distance(const Point& a_first_point, const Point& a_second_point) {
  return a_first_point.Distance(a_second_point);
}