#pragma once

#include "Point.h"

/** @brief Class edge represent a line between two points.
* 
*   Class edge represent a linear segment between two points. The two points are located at position (0.0,0.0,0.0) from default.
*   We can set the initial and final points by using the functions SetInitialPoint and SetFinalPoint.
*   We can get the initial and the final point by using the functions GetInitialPoint and GetFinalPoint.
*   The function IsAVertex indicates if the passed point is one of the two vertices.
*   The function IsNull indicates if the edge has zero length, i.e., the initial and the final points are the same.
* 
*   @code
*   Point finalPoint;
*   finalPoint.SetCoordinates(4.0, 4.5, 1.1);
*   Point initialPoint;
*   initialPoint.SetCoordinates(3.0, 4.5, 1.1);
*   Edge theEdge;
*   theEdge.SetFinalPoint(finalPoint);
*   theEdge.SetInitialPoint(initialPoint);
*   if ( theEdge.IsAVertex(finalPoint) && theEdge.IsAVertex(initialPoint)) {
*     ...
*   }
*   if (theEdge.IsNull()) {
*     ...
*   }
*   @endcode
*/
class Edge: public GeomObject
{
public:
  /** Default Constructor
  */
  Edge();

  /** Constructor from two points
  */
  Edge(const Point a_firstPoint, Point a_secondPoint);

  /** Default Destructor
  */
  ~Edge();

  /** Set the initial point in the edge
  */
  void SetInitialPoint(const Point a_firstPoint);

  /** Set the final point in the edge
  */
  void SetFinalPoint(const Point a_secondPoint);

  /** Back the initial point in the edge
  */
  Point GetInitialPoint() const;

  /** Back the final point in the edge
  */
  Point GetFinalPoint() const;

  /** Indicates if the passed point is one of the vertices of the edge.
  */
  bool IsAVertex(const Point& a_point) const;

  /** Indicates if the edge is null.
  */
  bool IsNull() const;

protected:
  /** The initial point in the edge
  */
  Point _initialPoint;

  /** The final point in the edge
  */
  Point _finalPoint;
};

