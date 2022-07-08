#include "pch.h"
#include "GeomObject.h"


double GeomObject::_defaultTolerance = 0.000001;

GeomObject::GeomObject() {
  _tolerance = GeomObject::_defaultTolerance;
}

GeomObject::~GeomObject() {

}

void GeomObject::SetTolerance(const double a_tolerance) {
  _tolerance = a_tolerance;
}

double GeomObject::GetTolerance() const {
  return _tolerance;
}

double GeomObject::GetDefaultTolerance() {
  return GeomObject::_defaultTolerance;
}