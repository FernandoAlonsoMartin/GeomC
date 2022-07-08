#include "GeomObjectTests.h"

#include "GeomObject.h"
#include "Point.h"

TEST(GeomObjectTests, DefaultTolerance) {  
  EXPECT_LE(GeomObject::GetDefaultTolerance(),0.00001);
  EXPECT_GE(GeomObject::GetDefaultTolerance(), 0.0000001);
}

TEST(GeomObjectTests, Tolerances) {
  Point thePoint;
  EXPECT_NEAR(thePoint.GetTolerance(), 0.000001, GeomObject::GetDefaultTolerance());
  thePoint.SetTolerance(0.0001);
  EXPECT_NEAR(thePoint.GetTolerance(), 0.0001, GeomObject::GetDefaultTolerance());
}