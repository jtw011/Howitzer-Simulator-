/***********************************************************************
 * Header File:
 *    POSITION
 * Author:
 *    Caleb Schmid, Chisom Wonodi, Tanner Williams
 * Summary:
 *    Everything we need to know about a location on the screen.
 ************************************************************************/


#pragma once

#include <iostream> 
#include <cmath>

class TestPosition;
class Acceleration;
class Velocity;
class TestGround;
class TestHowitzer;
class TestProjectile;


/*********************************************
 * Position
 * A single position on the field in Meters
 *********************************************/
class Position
{
public:
   friend ::TestPosition;     // for the unit tests
   friend ::TestGround;       // for the unit tests
   friend ::TestHowitzer;     // for the unit tests
   friend ::TestProjectile;   // for the unit tests


   // constructors
   Position()                   : x(0.0), y(0.0)   {}
   Position(double x, double y);
   Position(const Position& pt) : x(pt.x), y(pt.y) {}
   Position& operator = (const Position& pt);

   // getters
   double getMetersX()       const { return x; }
   double getMetersY()       const { return y; }
   double getPixelsX()       const { return x / metersFromPixels; }
   double getPixelsY()       const { return y / metersFromPixels; }
   double getZoom()          const { return metersFromPixels; }

   // setters
   void setZoom(double metersFromPixels) { this->metersFromPixels = metersFromPixels; }
   void setMeters(double xMeters, double yMeters) { x = xMeters; y = yMeters; }
   void setMetersX(double xMeters)     { x = xMeters; }
   void setMetersY(double yMeters)     { y = yMeters; }
   void setPixelsX(double xPixels)     { x = xPixels * metersFromPixels; }
   void setPixelsY(double yPixels)     { y = yPixels * metersFromPixels; }
   void addMetersX(double dxMeters)    { setMetersX(getMetersX() + dxMeters); }
   void addMetersY(double dyMeters)    { setMetersY(getMetersY() + dyMeters); }
   void addPixelsX(double dxPixels)    { setPixelsX(getPixelsX() + dxPixels); }
   void addPixelsY(double dyPixels)    { setPixelsY(getPixelsY() + dyPixels); }
   
   void add(const Acceleration& a, const Velocity& v, double t);

   void reverse() { }


private:
   double x;                 // horizontal position
   double y;                 // vertical position
   static double metersFromPixels;
};



// stream I/O useful for debugging
std::ostream& operator << (std::ostream& out, const Position& pt);
std::istream& operator >> (std::istream& in, Position& pt);


/*********************************************
 * PT
 * Trivial point
 *********************************************/
struct PT
{
   double x;
   double y;
};


