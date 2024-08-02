  /**********************************************************************
 * Suurce File:
 *    SIMULATION
 * Author:
 *    Caleb Schmid, Chisom Wonodi, Tanner Williams
 * Summary:
 *    Execute one simulation of a projectile being fired.
 ************************************************************************/

 #include "simulation.h"  // for SIMULATION

void Simulator::input(const Interface* pUI)
{
   double rotateRate = 0.05;
   double raiseRate = 0.003;  // in radians

   if (pUI->isRight())
      howitzer.rotate(rotateRate);
   if (pUI->isLeft())
      howitzer.rotate(-rotateRate);

   if (pUI->isUp())
      howitzer.raise(raiseRate);
   if (pUI->isDown())
      howitzer.raise(-raiseRate);

   if (pUI->isSpace() && !projectile.flying())
      fire();
}

void Simulator::advance()
{
   simTime += interval;
   projectile.advance(simTime);

   if (getHeightMeters() < ground.getElevationMeters(projectile.getPosition()))
   {
      simTime = 0;
      projectile.reset();
      status = AIMING;
   }
   else if (hitTarget())
      reset();
}

bool Simulator::hitTarget()
{
   Position t = ground.getTarget();
   Position p = projectile.getPosition();

   double tolerance = 6.0;  // how close we get to the target in pixels and have it count as a hit

   // check if the position of the projectile is close enough to the position of the target
   if (abs(t.getPixelsX() - p.getPixelsX()) <= tolerance &&
      abs(t.getPixelsY() - p.getPixelsY()) <= tolerance)
   {
      return true;
   }
   else
      return false;
}

void Simulator::display()
{
   ogstream gout(Position(10.0, howitzer.getPosition().getPixelsY() - 20.0));
   
   // draw ground and lines
   ground.draw(gout);

   // draw howitzer
   gout.drawHowitzer(howitzer.getPosition(), howitzer.getElevation().getRadians(), simTime);

   // draw projectile
   projectile.draw(gout);

   // draw some text on the screen
   displayText();
}

void Simulator::displayText()
{
   ogstream gout(Position(23000.0, 19000.0));

   // display degrees from - 180 to 180 instead of 0 to 360
   double degrees = howitzer.getElevation().getDegrees();
   if (degrees > 180.0)
      degrees -= 360.0;

   gout.setf(ios::fixed | ios::showpoint);
   gout.precision(1);
   if (status == AIMING)
      gout << "angle: " << degrees << "degree";
   if (status == FLYING)
      gout << "altitude:     " << projectile.getAltitude()       << "m\n"
           << "speed:       " << projectile.getSpeed()          << "m/s\n"
           << "distance:    " << projectile.getFlightDistance() << "m\n"
           << "hang time:  " << projectile.getFlightTime() / 10.0     << "s\n";

}