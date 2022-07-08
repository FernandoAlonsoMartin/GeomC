#include "pch.h"
#include "Wire.h"


Wire::Wire() : GeomObject() {

}

/** Default Destructor
*/
Wire::~Wire() {

}

void Wire::Add(const Edge& a_edge) {
  _edges.push_back(a_edge);
}

bool Wire::IsConcatenated() const {
  if (_edges.size() == 0) { 
    return false; 
  }

  if (_edges.size() == 1) {
    return (_edges.front().IsNull());
  }
  Point lastPoint = _edges.front().GetInitialPoint();
  for (Edge currentEdge: _edges) {
    if (currentEdge.IsNull()) {
      return false;
    }
    if (currentEdge.GetInitialPoint().Distance(lastPoint) > GetTolerance()) {
      return false;
    }
    lastPoint = currentEdge.GetFinalPoint();
  }

  return true;
}

bool Wire::IsClose() const {
  if (IsConcatenated() == false) {
    return false;
  }

  return (_edges.front().GetInitialPoint().Distance(_edges.back().GetFinalPoint()) < GetTolerance());
}

bool Wire::IsAVertex(const Point& a_point) const {
  if (_edges.size() == 0) {
    return false;
  }

  for (Edge currentEdge : _edges) {
    if (currentEdge.GetInitialPoint().Distance(a_point) > GetTolerance()) {
      return false;
    }
  }

  return true;
}

bool Wire::IsNull() const {
  return _edges.empty();
}