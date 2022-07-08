#pragma once

/** @brief Base class for the rest of the geometrical objects.
*   Base class for the rest of the geometrical objects. It just define the tolerance for all geometrical objects.
*   The default value of the tolerance of the geometrical object is _defaultTolerance, which is a static member. We can set the tolerance by using the function SetTolerance.
*   The function GetDefaultTolerance backs the defaut value used for the tolerance.
* 
*   @code
*   Point thePoint;
*   thePoint.SetTolerance(0.0001);
*   if (thePoint.GetTolerance() > GeomObject::GetDefaultTolerance()) {
*     ....
*   }
*   @endcode
*/
class GeomObject
{
public:
  /** Default Constructor
  */
  GeomObject();

  /** Default Destructor
  */
  ~GeomObject();

  /** Set the value of the tolerance for the geometrical object
  */
  void SetTolerance(const double a_tolerance);

  /** Back the value of the tolerance for the geometrical object
  */
  double GetTolerance() const;

  /** Back the value of the default tolerance for the geometrical object
  */
  static double GetDefaultTolerance();

protected:
  /** The tolerance for the geometrical object
  */
  double _tolerance;

  /** The default tolerance
  */
  static double _defaultTolerance;
};

