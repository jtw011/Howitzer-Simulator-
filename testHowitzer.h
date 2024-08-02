/***********************************************************************
 * Header File:
 *    TEST HOWITZER
 * Author:
 *    <your name here>
 * Summary:
 *    All the unit tests for Howitzer
 ************************************************************************/


#pragma once

#include "howitzer.h"
#include "unitTest.h"

/*******************************
 * TEST HOWITZER
 * A friend class for Howitzer which contains the Howitzer unit tests
 ********************************/
class TestHowitzer : public UnitTest
{
public:
   void run()
   {
      // Ticket 1: Getters
      defaultConstructor();
      getPosition_zero();
      getPosition_middle();
      getMuzzleVelocity_slow();
      getMuzzleVelocity_standard();
      getElevation_up();
      getElevation_right();
      getElevation_left();

      // Ticket 2: Setters
      generatePosition_small();
      generatePosition_large();
      raise_rightDown();
      raise_rightUp();
      raise_leftDown();
      raise_leftUp();
      rotate_clock();
      rotate_counterClock();
      rotate_wrapClock();
      rotate_wrapCounterClock();

      report("Howitzer");
   }

private:
   double metersFromPixels = -1.0;

   /*****************************************************************
    *****************************************************************
    * CONSTRUCTOR
    *****************************************************************
    *****************************************************************/

    /*********************************************
     * name:    DEFAULT CONSTRUCTOR
     * input:   nothing
     * output:  zeros
     *********************************************/
   void defaultConstructor()
   {  // SETUP
      setupStandardFixture();

      // EXERCISE
      Howitzer h;

      // VERIFY
      assertEquals(h.position.x, 0.0);
      assertEquals(h.position.y, 0.0);
      assertEquals(h.muzzleVelocity, 827.00);
      assertEquals(h.elevation.radians, M_PI / 4.0);

      // TEARDOWN
      teardownStandardFixture();
   }  

   /*****************************************************************
    *****************************************************************
    * GETTERS
    *****************************************************************
    *****************************************************************/

    /*********************************************
     * name:    GET POSITION ZERO
     * input:   h.pos=(0,0)
     * output:  pos=(0,0)
     *********************************************/
   void getPosition_zero()
   {  // SETUP
      setupStandardFixture();
      Howitzer h;
      h.position.x = 0.0;
      h.position.y = 0.0;
      Position pos;
      pos.x = -77.7;
      pos.y = -66.6;

      // EXERCISE
      pos = h.getPosition();

      // VERIFY
      assertEquals(pos.x, 0.0);
      assertEquals(pos.y, 0.0);
      assertEquals(h.position.x, 0.0);
      assertEquals(h.position.y, 0.0);
      assertEquals(h.muzzleVelocity, 827.00);
      assertEquals(h.elevation.radians, M_PI / 4.0);

      // TEARDOWN
      teardownStandardFixture();
   }  

   /*********************************************
    * name:    GET POSITION MIDDLE
     * input:   h.pos=(123.4, 567.8)
     * output:  pos=(123.4, 567.8)
    *********************************************/
   void getPosition_middle()
   {  // SETUP
      setupStandardFixture();
      Howitzer h;
      h.position.x = 123.4;
      h.position.y = 567.8;
      Position pos;
      pos.x = -77.7;
      pos.y = -66.6;

      // EXERCISE
      pos = h.getPosition();

      // VERIFY
      assertEquals(pos.x, 123.4);
      assertEquals(pos.y, 567.8);
      assertEquals(h.position.x, 123.4);
      assertEquals(h.position.y, 567.8);
      assertEquals(h.muzzleVelocity, 827.00);
      assertEquals(h.elevation.radians, M_PI / 4.0);

      // TEARDOWN
      teardownStandardFixture();
   }  

   /*********************************************
    * name:    GET MUZZLE VELOCITY - SLOW SPEED
     * input:   h.muzzleVelocity=(24.68)
     * output:  m=24.68
    *********************************************/
   void getMuzzleVelocity_slow()
   {  // SETUP
      setupStandardFixture();
      Howitzer h;
      h.muzzleVelocity = 24.68;
      double m = 99.99;

      // EXERCISE
      m = h.getMuzzleVelocity();

      // VERIFY
      assertEquals(m, 24.68);
      assertEquals(h.muzzleVelocity, 24.68);
      
      // TEARDOWN
      teardownStandardFixture();
   }  

   /*********************************************
    * name:    GET MUZZLE VELOCITY - STANDARD SPEED
     * input:   h.muzzleVelocity=(827.00)
     * output:  m=827
    *********************************************/
   void getMuzzleVelocity_standard()
   {  // SETUP
      Howitzer h;
      h.muzzleVelocity = 827.00;
      double m = 99.99;

      // EXERCISE
      m = h.getMuzzleVelocity();

      // VERIFY
      assertEquals(m, 827.00);
      assertEquals(h.muzzleVelocity, 827.00);

      // TEARDOWN
      teardownStandardFixture();
   }

   /*********************************************
    * name:    GET ELEVATION - up
     * input:   h.elevation=0
     * output:  e=0
    *********************************************/
   void getElevation_up()
   {  // SETUP
      setupStandardFixture();
      Howitzer h;
      h.elevation.radians = 0.0;
      Angle e;
      e.radians = -99.9;

      // EXERCISE
      e = h.getElevation();

      // VERIFY
      assertEquals(e.radians, 0.0);
      assertEquals(h.elevation.radians, 0.0);

      // TEARDOWN
      teardownStandardFixture();
   }  

   /*********************************************
    * name:    GET ELEVATION - right
     * input:   h.elevation=0.4
     * output:  e=0.4
    *********************************************/
   void getElevation_right()
   {  // SETUP
      setupStandardFixture();
      Howitzer h;
      h.elevation.radians = 0.4;
      Angle e;
      e.radians = -99.9;

      // EXERCISE
      e = h.getElevation();

      // VERIFY
      assertEquals(e.radians, 0.4);
      assertEquals(h.elevation.radians, 0.4);

      // TEARDOWN
      teardownStandardFixture();
   }

   /*********************************************
    * name:    GET ELEVATION - left
     * input:   h.elevation=5.8
     * output:  e=5.8
    *********************************************/
   void getElevation_left()
   {  // SETUP
      setupStandardFixture();
      Howitzer h;
      h.elevation.radians = 5.8;
      Angle e;
      e.radians = -99.9;


      // EXERCISE
      e = h.getElevation();

      // VERIFY
      assertEquals(e.radians, 5.8);
      assertEquals(h.elevation.radians, 5.8);

      // TEARDOWN
      teardownStandardFixture();
   }

   /*****************************************************************
    *****************************************************************
    * SETTERS
    *****************************************************************
    *****************************************************************/

    /*********************************************
     * name:    GENERATE POSITION small board
     * input:   (10px, 10px)
     * output:  0 <= x <= 9
     *********************************************/
   void generatePosition_small()
   {  // SETUP
      setupStandardFixture();
      Position posUpperRight;
      posUpperRight.x = 11000.0;
      posUpperRight.y = 11000.0;
      Howitzer h;
      h.elevation.radians = 0.222;
      h.position.x = 220000.0;
      h.position.y = 220000.0;

      // EXERCISE
      h.generatePosition(posUpperRight);

      // VERIFY
      assertUnit(1.0 <= h.position.x && h.position.x <= 9900.0); // 0 <= xPixel <= 9
      assertEquals(h.position.y, 0.0);
      assertEquals(h.muzzleVelocity, 827.00);
      assertEquals(h.elevation.radians, 0.222);

      // TEARDOWN
      teardownStandardFixture();
   }  

    /*********************************************
    * name:    GENERATE POSITION large board
    * input:   (1000px, 1000px)
    * output:  0 <= x <= 900
    *********************************************/
   void generatePosition_large()
   {  // SETUP
      setupStandardFixture();
      Position posUpperRight;
      posUpperRight.x = 1100000.0;
      posUpperRight.y = 1100000.0;
      Howitzer h;
      h.elevation.radians = 0.222;
      h.position.x = 2200000.0;
      h.position.y = 2200000.0;

      // EXERCISE
      h.generatePosition(posUpperRight);

      // VERIFY
      assertUnit(110000.0 <= h.position.x && h.position.x <= 990000.0); // 0 <= xPixel <= 9
      assertEquals(h.position.y, 0.0);
      assertEquals(h.muzzleVelocity, 827.00);
      assertEquals(h.elevation.radians, 0.222);

      // TEARDOWN
      teardownStandardFixture();
   }

   /*********************************************
    * name:    RAISE to the right/down
    * input:   h.elevation=0.5radians  raise(-0.1)
    * output:  h.elevation=0.6radians
    *********************************************/
   void raise_rightDown()
   {  // SETUP
      setupStandardFixture();
      Howitzer h;
      h.position.x = 1.1;
      h.position.y = 2.2;
      h.elevation.radians = 0.5;

      // EXERCISE
      h.raise(-0.1);

      // VERIFY
      assertEquals(h.position.x, 1.1);
      assertEquals(h.position.y, 2.2);
      assertEquals(h.muzzleVelocity, 827.00);
      assertEquals(h.elevation.radians, 0.6);

      // TEARDOWN
      teardownStandardFixture();
   }

   /*********************************************
    * name:    RAISE to the right/up
    * input:   h.elevation=0.5radians  raise(0.1)
    * output:  h.elevation=0.4radians
    *********************************************/
   void raise_rightUp()
   {  // SETUP
      setupStandardFixture();
      Howitzer h;
      h.position.x = 1.1;
      h.position.y = 2.2;
      h.elevation.radians = 0.5;

      // EXERCISE
      h.raise(0.1);

      // VERIFY
      assertEquals(h.position.x, 1.1);
      assertEquals(h.position.y, 2.2);
      assertEquals(h.muzzleVelocity, 827.00);
      assertEquals(h.elevation.radians, 0.4);

      // TEARDOWN
      teardownStandardFixture();
   }

   /*********************************************
    * name:    RAISE to the left down
    * input:   h.elevation=-0.5radians  raise(-0.1)
    * output:  h.elevation=-0.6radians
    *********************************************/
   void raise_leftDown()
   {  // SETUP
      setupStandardFixture();
      Howitzer h;
      h.position.x = 1.1;
      h.position.y = 2.2;
      h.elevation.radians = (M_PI * 2.0) - 0.5;

      // EXERCISE
      h.raise(-0.1);

      // VERIFY
      assertEquals(h.position.x, 1.1);
      assertEquals(h.position.y, 2.2);
      assertEquals(h.muzzleVelocity, 827.00);
      assertEquals(h.elevation.radians, (M_PI * 2.0) - 0.6);

      // TEARDOWN
      teardownStandardFixture();
   }

   /*********************************************
    * name:    RAISE to the left up
    * input:   h.elevation=-0.5radians  raise(0.1)
    * output:  h.elevation=-0.4radians
    *********************************************/
   void raise_leftUp()
   {  // SETUP
      setupStandardFixture();
      Howitzer h;
      h.position.x = 1.1;
      h.position.y = 2.2;
      h.elevation.radians = (M_PI * 2.0) - 0.5;

      // EXERCISE
      h.raise(0.1);

      // VERIFY
      assertEquals(h.position.x, 1.1);
      assertEquals(h.position.y, 2.2);
      assertEquals(h.muzzleVelocity, 827.00);
      assertEquals(h.elevation.radians, (M_PI * 2.0) - 0.4);

      // TEARDOWN
      teardownStandardFixture();
   }

   /*********************************************
    * name:    ROTATE CLOCKWISE no wrapping
    * input:   h.elevation=1.23 rotate=.3
    * output:  h.elevation=1.53
    *********************************************/
   void rotate_clock()
   {  // SETUP
      setupStandardFixture();
      Howitzer h;
      h.elevation.radians = 1.23;

      // EXERICSE
      h.rotate(0.3);

      // VERIFY
      assertEquals(h.elevation.radians, 1.53);

      // TEARDOWN
      teardownStandardFixture();
   }

   /*********************************************
    * name:    ROTATE COUNTER CLOCKWISE no wrapping
    * input:   h.elevation=1.23 rotate=-.3
    * output:  h.elevation=0.93
    *********************************************/
   void rotate_counterClock()
   {  // SETUP
      setupStandardFixture();
      Howitzer h;
      h.elevation.radians = 1.23;

      // EXERICSE
      h.rotate(-0.3);

      // VERIFY
      assertEquals(h.elevation.radians, 0.93);

      // TEARDOWN
      teardownStandardFixture();
   }

   /*********************************************
    * name:    ROTATE CLOCKWISE CLOCKWISE WRAP BY 2PI
    * input:   h.elevation=6.1 rotate=.2
    * output:  h.elevation=.1
    *********************************************/
   void rotate_wrapClock()
   {  // SETUP
      setupStandardFixture();
      Howitzer h;
      h.elevation.radians = M_PI * 2.0 - 0.1;

      // EXERICSE
      h.rotate(0.2);

      // VERIFY
      assertEquals(h.elevation.radians, 0.1);

      // TEARDOWN
      teardownStandardFixture();
   }

   /*********************************************
    * name:    ROTATE COUNTER CLOCKWISE WRAP BY 4PI
    * input:   h.elevation=0.1 rotate=-.2 - 4PI
    * output:  h.elevation=6.1
    *********************************************/
   void rotate_wrapCounterClock()
   {  // SETUP
      setupStandardFixture();
      Howitzer h;
      h.elevation.radians = 0.1;

      // EXERICSE
      h.rotate(-0.2 - (4.0 * M_PI));

      // VERIFY
      assertEquals(h.elevation.radians, M_PI * 2.0 - 0.1);

      // TEARDOWN
      teardownStandardFixture();
   }

   /*****************************************************************
    *****************************************************************
    * STANDARD FIXTURE
    *****************************************************************
    *****************************************************************/

   // setup standard fixture - set the zoom to 1100m per pixel
   void setupStandardFixture()
   {
      Position p;
      metersFromPixels = p.metersFromPixels;
      p.metersFromPixels = 1100.0;
   }

   // teardown the standard fixture - reset the zoom to what it was previously
   void teardownStandardFixture()
   {
      assert(metersFromPixels != -1.0);
      Position p;
      p.metersFromPixels = metersFromPixels;
   }
};
