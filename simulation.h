/**********************************************************************
 * Header File:
 *    SIMULATION
 * Author:
 *    Caleb Schmid, Chisom Wonodi, Tanner Williams
 * Summary:
 *    Execute one simulation of a projectile being fired.
 ************************************************************************/

#pragma once
#include "position.h"    // everything should have a point
#include "acceleration.h"// for ACCELERATION
#include "howitzer.h"    // for HOWITZER
#include "projectile.h"  // for PROJECTILE
#include "uiInteract.h"  // for INTERFACE
#include "uiDraw.h"      // for RANDOM and DRAW*
#include "ground.h"      // for GROUND
#include "test.h"        // for the unit tests
#include <cmath>         // for SQRT
#include <cassert>       // for ASSERT
#include <vector>        // for storing stars
using namespace std;

enum Status{AIMING, FLYING, MISS, HIT};

 /*********************************************
  * Simulation
  * Execute one simulation of a projectile being fired.
  *********************************************/
class Simulator
{
public:
   Simulator(const Position & posUpperRight) : 
      posUpperRight(posUpperRight),
      interval(0.55),
      status(AIMING),
      simTime(0.0),
      ground(posUpperRight)
   {
      howitzer.generatePosition(posUpperRight);
      projectile.reset();
      ground.reset(howitzer.getPosition());
   };
   void reset()
   {
      simTime = 0.0;
      howitzer.generatePosition(posUpperRight);
      projectile.reset();
      ground.reset(howitzer.getPosition());
   }
   void fire()
   { 
      status = FLYING;
      simTime = 0.0;
      projectile.fire(howitzer.getPosition(), howitzer.getElevation(), simTime, DEFAULT_MUZZLE_VELOCITY);
   }
   void display();
   void advance();
   void input(const Interface* pUI);
   void setInterval(double interval) { this->interval = interval; }
   void setMuzzleVelocity(double vel) {}
   void setDiameter(double diameter) { projectile.setRadius(diameter / 2.0); }

private:
   bool hitTarget();
   double getHeightMeters() 
   { 
      return projectile.getPosition().getMetersY();
   }
   void displayText();

   Position posUpperRight;
   double interval;
   Howitzer howitzer;
   Projectile projectile;
   Status status;
   double simTime;
   Ground ground;
};
