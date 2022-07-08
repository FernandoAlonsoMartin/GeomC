#include "PointTests.h"

#include "Point.h"

TEST(PointTests, CreatePointAndSetCoordinates) {
  Point thePoint;
  thePoint.SetCoordinates(3.0, 4.5, 1.1);
  EXPECT_NEAR(thePoint.GetX(),3.0, GeomObject::GetDefaultTolerance());
  EXPECT_NEAR(thePoint.GetY(), 4.5, GeomObject::GetDefaultTolerance());
  EXPECT_NEAR(thePoint.GetZ(), 1.1, GeomObject::GetDefaultTolerance());
}

TEST(PointTests, CreatePointAndSetValues) {
  Point thePoint;
  thePoint.SetX(3.0);
  thePoint.SetY(4.5);
  thePoint.SetZ(1.1);
  EXPECT_NEAR(thePoint.GetX(), 3.0, GeomObject::GetDefaultTolerance());
  EXPECT_NEAR(thePoint.GetY(), 4.5, GeomObject::GetDefaultTolerance());
  EXPECT_NEAR(thePoint.GetZ(), 1.1, GeomObject::GetDefaultTolerance());
}

TEST(PointTests, DistanceBetweenPoints) {
  Point firstPoint;
  firstPoint.SetCoordinates(3.0, 4.5, 1.1);
  Point secondPoint;
  secondPoint.SetCoordinates(4.0, 4.5, 1.1);
  EXPECT_NEAR(firstPoint.Distance(secondPoint), 1.0, GeomObject::GetDefaultTolerance());
  EXPECT_NEAR(Point::Distance(firstPoint,secondPoint), 1.0, GeomObject::GetDefaultTolerance());
}

TEST(PointTests, Tolerances) {
  Point thePoint;
  EXPECT_NEAR(thePoint.GetTolerance(), 0.000001, GeomObject::GetDefaultTolerance());
  thePoint.SetTolerance(0.0001);
  EXPECT_NEAR(thePoint.GetTolerance(), 0.0001, GeomObject::GetDefaultTolerance());
}

