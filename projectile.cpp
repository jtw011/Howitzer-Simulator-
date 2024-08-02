/***********************************************************************
 * Source File:
 *    PROJECTILE
 * Author:
 *    <your name here>
 * Summary:
 *    Everything we need to know about a projectile
 ************************************************************************/


#include "projectile.h"
#include "angle.h"
using namespace std;

void Projectile::fire(const Position& posHowitzer, const Angle& elevation, double simulationTime, double muzzleVelocity)
{
   // clear the flight path
   reset();

   // create initial position
   PositionVelocityTime pvt;
   pvt.pos = posHowitzer;
   pvt.t = simulationTime;
   pvt.v.set(elevation, muzzleVelocity);
   flightPath.push_back(pvt);
}

void Projectile::advance(double simulationTime)
{
   // If projectile is not flying, nothing moves
   if (!flying()) {
      return;
   }

   // the interval is the time since the last timestamp
     
   // Next PVT will be based off the last one
   PositionVelocityTime pvt = flightPath.back();
   double speed = pvt.v.getSpeed();
   double altitude = pvt.pos.getMetersY();
   double interval = simulationTime - currentTime();
   assert(interval > 0.0);
   
   // Get all the factors that will affect position (interpolated)
   double density          = densityFromAltitude(altitude);
   double speedSound     = speedSoundFromAltitude(altitude);
   double mach             = speed / speedSound;
   double dragCoefficient  = dragFromMach(mach);
   double windResistance   = forceFromDrag(density, dragCoefficient,radius, speed);
   double magnitudeWind    = accelerationFromForce(windResistance, mass);
   Acceleration aWind(-pvt.v.getAngle(), magnitudeWind);

   // Gravity
   double magnitudeGravity = gravityFromAltitude(altitude);
   Angle angleGravity;
   angleGravity.setDown();
   Acceleration aGravity(angleGravity, magnitudeGravity);

   // Total accleration
   Acceleration aTotal = aGravity + aWind;

   // Update flightPath
   pvt.pos.add(aTotal, pvt.v, interval);
   pvt.v.add(aTotal, interval);
   pvt.t = simulationTime;

   // Add to the back of the list
   flightPath.push_back(pvt);
}
