#include "pch.h"
#include "Edge.h"

Edge::Edge() : GeomObject() {

}

Edge::Edge(const Point a_firstPoint, Point a_secondPoint) : GeomObject() {
  _initialPoint = a_firstPoint;
  _finalPoint = a_secondPoint;
}

/** Default Destructor
*/
Edge::~Edge() {

}

void Edge::SetInitialPoint(const Point a_firstPoint) {
  _initialPoint = a_firstPoint;
}

void Edge::SetFinalPoint(const Point a_secondPoint) {
  _finalPoint = a_secondPoint;
}

Point Edge::GetInitialPoint() const {
  return _initialPoint;
}

Point Edge::GetFinalPoint() const {
  return _finalPoint;
}

bool Edge::IsAVertex(const Point& a_point) const {
  if (a_point.Distance(_initialPoint) < _tolerance) {
    return true;
  }
  else if (a_point.Distance(_finalPoint) < _tolerance) {
    return true;
  }
  return false;
}

bool Edge::IsNull() const {
  return (_initialPoint.Distance(_finalPoint) < _tolerance);
}