/***********************************************************************
 * Source File:
 *    ACCELERATION
 * Author:
 *    Caleb Schmid, Chisom Wonodi, Tanner Williams
 * Summary:
 *    Everything we need to know about changing speed
 ************************************************************************/

#include "acceleration.h"
#include "angle.h"

#include <cmath>



 /*********************************************
  * ACCELERATION : SET
  *  set from angle and direction
  *********************************************/
void Acceleration::set(const Angle& angle, double magnitude)
{
   ddx = sin(angle.getRadians()) * magnitude;
   ddy = cos(angle.getRadians()) * magnitude;
}

void Acceleration::add(const Acceleration& rhs)
{
   ddx += rhs.getDDX();
   ddy += rhs.getDDY();
}
