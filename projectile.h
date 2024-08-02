/**********************************************************************
 * Header File:
 *    PROJECTILE
 * Author:
 *    <your name here>
 * Summary:
 *    Everything we need to know about a projectile
 ************************************************************************/

#pragma once

#include <list>
#include "position.h"
#include "velocity.h"
#include "acceleration.h"
#include "physics.h"
#include "uiDraw.h"

#define DEFAULT_PROJECTILE_WEIGHT 46.7       // kg
#define DEFAULT_PROJECTILE_RADIUS 0.077545   // m

// forward declaration for the unit test class
class TestProjectile; 

 /**********************************************************************
  * Projectile
  *    Everything we need to know about a projectile
  ************************************************************************/
class Projectile
{
public:
   // Friend the unit test class
   friend ::TestProjectile;

   // create a new projectile with the default settings
   Projectile() : mass(DEFAULT_PROJECTILE_WEIGHT),
      radius(DEFAULT_PROJECTILE_RADIUS) {}

   // resets everything to default and clears flightPath
   void reset() 
   {
      flightPath.clear();
      mass = DEFAULT_PROJECTILE_WEIGHT; 
      radius = DEFAULT_PROJECTILE_RADIUS;
   }

   // advance the round forward until the next unit of time
   void advance(double simulationTime);
   // put the first pvt in the flightPath
   void fire(const Position& posHowitzer, 
      const Angle& elevation, 
      double simulationTime,
      double muzzleVelocity);

   void draw(ogstream& gout) const
   {
      for (auto it = flightPath.cbegin(); it != flightPath.cend(); ++it)
         gout.drawProjectile(it->pos, currentTime() - it->t);
   }

   // is the projectile flying?
   bool flying() const { return !flightPath.empty(); }

   // what is the altitude of the round?
   double getAltitude() const { return flying() ? flightPath.back().pos.getMetersY() : 0; }

   Position getPosition() const { return flying() ? flightPath.back().pos : Position(); }

   // how long has the round been in the air?
   double getFlightTime() const 
   {
      return (flightPath.size() >= 2) ? flightPath.back().t - flightPath.front().t : 0.0;
   }

   // how far has the round traveled?
   double getFlightDistance() const
   {
      return (flightPath.size()) ?
         abs(flightPath.front().pos.getMetersX() - flightPath.back().pos.getMetersX()) : 0.0;
   }

   // how fast is the round traveling right now?
   double getSpeed() const { return flying() ? flightPath.back().t : 0.0; }

   // what time is it right now?
   double currentTime() const { return flying() ? flightPath.back().t : 0.0; }

   // set mass of the round
   void setMass(double mass) { this->mass = mass; }

   // set radius of the round
   void setRadius(double radius) { this->radius = radius; }

private:

   // keep track of one moment in the path of the projectile
   struct PositionVelocityTime
   {
      PositionVelocityTime() : pos(), v(), t(0.0) {}
      PositionVelocityTime(Position pos, Velocity v, double t) : pos(pos), v(v), t(t) {}
      Position pos;
      Velocity v;
      double t;
   };

   double mass;           // weight of the M795 projectile. Defaults to 46.7 kg
   double radius;         // radius of M795 projectile. Defaults to 0.077545 m
   std::list<PositionVelocityTime> flightPath;
};