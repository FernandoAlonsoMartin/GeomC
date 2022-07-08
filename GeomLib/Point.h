#pragma once

#include "GeomObject.h"

/** @brief Declare a 3D point
*   
*   Declare a 3D point with three coordinates: x, y and z. The point is initially set to have coordinates (0.0,0.0,0.0). 
*   The values of the coordinates can be setted by using the functions SetX, SetY, SetZ and SetCoordinates. 
*   The values of the coordinates can be get by using the functions GetX, GetY, GetZ and GetCoordinates.
*   We can compute the distance between two points using the function Distance.
*
*   @code
*   Point firstPoint;
*   firstPoint.SetCoordinates(3.0, 4.5, 1.1);
*   Point secondPoint;
*   secondPoint.SetCoordinates(4.0, 4.5, 1.1);
*   double value = firstPoint.Distance(secondPoint);
*   @endcode
* 
*   @code
*   Point thePoint;
*   thePoint.SetX(3.0);
*   thePoint.SetY(4.5);
*   thePoint.SetZ(1.1);
*   @endcode
*/
class Point: public GeomObject
{
public:
  /** Default Constructor
  */
  Point();

  /** Default Destructor
  */
  ~Point();

  /** Set the X value of the coordinate
  */
  void SetX(const double a_x);

  /** Set the Y value of the coordinate
  */
  void SetY(const double a_y);

  /** Set the Z value of the coordinate
  */
  void SetZ(const double a_z);

  /** Set the coordinates
  */
  void SetCoordinates(const double a_x, const double a_y, const double a_z);

  /** Back the X value of the coordinate
  */
  double GetX() const;

  /** Back the Y value of the coordinate
  */
  double GetY() const;

  /** Back the Z value of the coordinate
  */
  double GetZ() const;

  /** Get the coordinates
  */
  void GetCoordinates(double& a_x, double& a_y, double& a_z);

  /** Distance operator between this point and the passed point.
  */
  double Distance(const Point& a_other_point) const;

  /** Distance operator between two points
  */
  static double Distance(const Point& a_first_point, const Point& a_second_point);

protected:

  /** X value of the coordinate
  */
  double _x;

  /** Y value of the coordinate
  */
  double _y;

  /** Z value of the coordinate
  */
  double _z;
};

