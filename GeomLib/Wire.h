#pragma once

#include "Edge.h"

#include <list>

/** @brief This class represent a set of edges. They can be either concatenated or not.
*   We add edges to the wire using the function Add.
*   We can tests if all the edges in the wire are concatenated using the function IsConcatenated
*   We can tests if all the edges in the wire are concatenated and close using the function IsClose
*   The function IsAVertex indicates if the passed point is one of the vertices of the wire.
*   The function IsNull indicates if the wire has zero edges
* 
*   @code
*   Wire theWire;
*   Edge theEdge;
*   Point thePoint;
*   thePoint.SetCoordinates(3.0, 4.5, 1.1);
*   theEdge.SetFinalPoint(thePoint);
*   theWire.Add(theEdge);
*
*   Edge theEdge2;
*   theEdge2.SetInitialPoint(thePoint);
*   Point thePoint2;
*   thePoint2.SetCoordinates(4.0, 4.5, 1.1);
*   theEdge2.SetFinalPoint(thePoint2);
*   theWire.Add(theEdge2);
*
*   Edge theEdge3;
*   theEdge3.SetInitialPoint(thePoint2);
*   theWire.Add(theEdge3);
*
*   if (theWire.IsConcatenated()) {
*     ...
*   }
*   if (theWire.IsClose()) {
*     ...
*   }
*   @endcode
*/
class Wire : public GeomObject
{
public:
  /** Default Constructor
  */
  Wire();

  /** Default Destructor
  */
  ~Wire();

  /** Add an edge to the wire
  */
  void Add(const Edge& a_edge);

  /** Indicated if all the edges are concatenated on the wire.
  */
  bool IsConcatenated() const;

  /** Indicated if all the edges wire is close.
  */
  bool IsClose() const;

  /** Indicates if the passed point is one of the vertices of the edge.
  */
  bool IsAVertex(const Point& a_point) const;

  /** Indicates if the edge is null.
  */
  bool IsNull() const;

protected:

  /** The list of edges conforming the wire
  */
  std::list<Edge> _edges;
};

