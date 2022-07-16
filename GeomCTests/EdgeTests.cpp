#include "EdgeTests.h"

#include "pch.h"

#include "Edge.h"

TEST(EdgeTests, TestNullEdge) {
  Edge theEdge;
  EXPECT_TRUE(theEdge.IsNull());
}

TEST(EdgeTests, TestNullEdgeAsFalse) {
  Point initialPoint;
  initialPoint.SetCoordinates(3.0, 4.5, 1.1);
  Edge theEdge;
  theEdge.SetInitialPoint(initialPoint);
  EXPECT_FALSE(theEdge.IsNull());
}

TEST(EdgeTests, TestNullEdgeAsTrue) {
  Point initialPoint;  
  Edge theEdge;
  theEdge.SetInitialPoint(initialPoint);
  EXPECT_TRUE(theEdge.IsNull());

  initialPoint.SetCoordinates(3.0, 4.5, 1.1);
  theEdge.SetInitialPoint(initialPoint);
  theEdge.SetFinalPoint(initialPoint);
  EXPECT_TRUE(theEdge.IsNull());
}

TEST(EdgeTests, TestIsAVertexAsTrue) {
  Point finalPoint;
  finalPoint.SetCoordinates(4.0, 4.5, 1.1);
  Point initialPoint;
  initialPoint.SetCoordinates(3.0, 4.5, 1.1);
  Edge theEdge;
  theEdge.SetFinalPoint(finalPoint);
  theEdge.SetInitialPoint(initialPoint);

  EXPECT_TRUE(theEdge.IsAVertex(finalPoint));
  EXPECT_TRUE(theEdge.IsAVertex(initialPoint));

  Point otherPoint;
  otherPoint.SetCoordinates(1.0, 1.5, 1.1);

  EXPECT_FALSE(theEdge.IsAVertex(otherPoint));
}

TEST(EdgeTests, TestEdgesVertices) {
  Point finalPoint;
  finalPoint.SetCoordinates(4.0, 4.5, 1.1);
  Point initialPoint;
  initialPoint.SetCoordinates(3.0, 4.5, 1.1);
  Edge theEdge;
  theEdge.SetFinalPoint(finalPoint);
  theEdge.SetInitialPoint(initialPoint);

  EXPECT_LE(theEdge.GetInitialPoint().Distance(initialPoint), theEdge.GetTolerance());
  EXPECT_LE(theEdge.GetFinalPoint().Distance(finalPoint), theEdge.GetTolerance());
}
