#include "WireTests.h"

#include "pch.h"

#include "Wire.h"

TEST(WireTests, TestNullWire) {
  Wire theWire;
  EXPECT_TRUE(theWire.IsNull());
}

TEST(WireTests, TestNotNullWireWithNullEdge) {
  Wire theWire;
  Edge theEdge;
  theWire.Add(theEdge);
  EXPECT_FALSE(theWire.IsNull());
}

TEST(WireTests, TestConcatenatedWireOnlyNullEdge) {
  Wire theWire;
  Edge theEdge;
  theWire.Add(theEdge);
  EXPECT_TRUE(theWire.IsConcatenated());
}

TEST(WireTests, TestNotConcatenatedWireOnlyOneEdge) {
  Wire theWire;
  Edge theEdge;
  Point thePoint;
  thePoint.SetCoordinates(3.0, 4.5, 1.1);
  theEdge.SetFinalPoint(thePoint);
  theWire.Add(theEdge);
  EXPECT_FALSE(theWire.IsConcatenated());
}

TEST(WireTests, TestConcatenatedNotCloseWire) {
  Wire theWire;
  Edge theEdge;
  Point thePoint;
  thePoint.SetCoordinates(3.0, 4.5, 1.1);
  theEdge.SetFinalPoint(thePoint);
  theWire.Add(theEdge);
  Edge theEdge2;
  theEdge2.SetInitialPoint(thePoint);
  Point thePoint2;
  thePoint2.SetCoordinates(4.0, 4.5, 1.1);
  theEdge2.SetFinalPoint(thePoint2);
  theWire.Add(theEdge2);
  EXPECT_TRUE(theWire.IsConcatenated());
  EXPECT_FALSE(theWire.IsClose());
}

TEST(WireTests, TestConcatenatedCloseWire) {
  Wire theWire;
  Edge theEdge;
  Point thePoint;
  thePoint.SetCoordinates(3.0, 4.5, 1.1);
  theEdge.SetFinalPoint(thePoint);
  theWire.Add(theEdge);

  Edge theEdge2;
  theEdge2.SetInitialPoint(thePoint);
  Point thePoint2;
  thePoint2.SetCoordinates(4.0, 4.5, 1.1);
  theEdge2.SetFinalPoint(thePoint2);
  theWire.Add(theEdge2);

  Edge theEdge3;
  theEdge3.SetInitialPoint(thePoint2);
  theWire.Add(theEdge3);

  EXPECT_TRUE(theWire.IsConcatenated());
  EXPECT_TRUE(theWire.IsClose());
}

TEST(WireTests, TestNotConcatenatedNotCloseWire) {
  Wire theWire;
  Edge theEdge;
  Point thePoint;
  thePoint.SetCoordinates(3.0, 4.5, 1.1);
  theEdge.SetFinalPoint(thePoint);
  theWire.Add(theEdge);
  Point thePoint3;
  thePoint3.SetCoordinates(3.5, 4.5, 1.1);
  Edge theEdge2;
  theEdge2.SetInitialPoint(thePoint3);
  Point thePoint2;
  thePoint2.SetCoordinates(4.0, 4.5, 1.1);
  theEdge2.SetFinalPoint(thePoint2);
  theWire.Add(theEdge2);
  EXPECT_FALSE(theWire.IsConcatenated());
  EXPECT_FALSE(theWire.IsClose());
}