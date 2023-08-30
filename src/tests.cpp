 #define BOOST_TEST_MODULE module_simulater_test

#include <ncurses.h>
#include <stdlib.h>
#include <iostream>

#include "model_simulator_breakout.h"
#include <view_console.h>
#include "controller_console.h"
 
 
Boost_AUTO_TEST_CASE(case1)
{
BreakoutModel* breakout = new BreakoutModel(); 
breakout->getBall()->setY(5);
breakout->getBall()->setX()
breakout->setDir(1)
int i = 0;
while(i != 3) {
    breakout->simulate_game_step();
}

}