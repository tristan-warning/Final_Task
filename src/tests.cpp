 #define BOOST_TEST_MODULE module_simulater_test

#include <ncurses.h>
#include <stdlib.h>
#include <iostream>

#include "model_simulator_breakout.h"
#include <view_console.h>
#include "controller_console.h"
 
//***************************************************************
//Paddle Tests
//***************************************************************

//Ball trifft Paddle gerade von oben -> der Ball soll sich wieder
//gerade nach oben bewegen
Boost_AUTO_TEST_CASE(case1)
{
BreakoutModel* breakout = new BreakoutModel(); 
int paddleX = breakout->getPaddle()->getX();
int paddleY = breakout->getPaddle()->getY();
breakout->getBall()->setY(paddleY+2);
breakout->getBall()->setX(paddleX);
breakout->setDir(1)
int i = 0;
while(i != 3) {
    breakout->simulate_game_step();
}
Boost_test(breakout->getPaddle()->getY() == paddleY+2,
breakout->getPaddle()->getX() == paddleX);
}

//Ball bewegt sich nach rechts unten und trifft auf den rechten Teil
//Paddels -> Der Ball soll nach oben rechts abgelenkt werden
Boost_AUTO_TEST_CASE(case2)
{
BreakoutModel* breakout = new BreakoutModel(); 
int paddleX = breakout->getPaddle()->getX();
int paddleY = breakout->getPaddle()->getY();
breakout->getBall()->setY(paddleY+2);
breakout->getBall()->setX(paddleX-1);
breakout->setDir(4)
int i = 0;
while(i != 3) {
    breakout->simulate_game_step();
}
Boost_test(breakout->getPaddle()->getY() == paddleY+2,
breakout->getPaddle()->getX() == paddleX+2);
}

//Ball bewegt sich nach unten links und trifft auf den rechten Teil
//Paddels -> Der Ball soll nach oben rechts abgelenkt werden
Boost_AUTO_TEST_CASE(case3)
{
BreakoutModel* breakout = new BreakoutModel(); 
int paddleX = breakout->getPaddle()->getX();
int paddleY = breakout->getPaddle()->getY();
breakout->getBall()->setY(paddleY+2);
breakout->getBall()->setX(paddleX+3);
breakout->setDir(6)
int i = 0;
while(i != 3) {
    breakout->simulate_game_step();
}
Boost_test(breakout->getPaddle()->getY() == paddleY+2,
breakout->getPaddle()->getX() == paddleX+3);
}

//Ball bewegt sich nach unten links und trifft auf den linken Teil
//Paddles -> Der Ball soll nach oben Links abgelengt werden
Boost_AUTO_TEST_CASE(case4)
{
BreakoutModel* breakout = new BreakoutModel(); 
int paddleX = breakout->getPaddle()->getX();
int paddleY = breakout->getPaddle()->getY();
breakout->getBall()->setY(paddleY+2);
breakout->getBall()->setX(paddleX+1);
breakout->setDir(6)
int i = 0;
while(i != 3) {
    breakout->simulate_game_step();
}
Boost_test(breakout->getPaddle()->getY() == paddleY+2,
breakout->getPaddle()->getX() == paddleX-3);
}

//Ball bewegt sich nach unten rechts und trifft auf den linken Teil
//Paddles -> Der Ball soll nach oben Links abgelengt werden
Boost_AUTO_TEST_CASE(case5)
{
BreakoutModel* breakout = new BreakoutModel(); 
int paddleX = breakout->getPaddle()->getX();
int paddleY = breakout->getPaddle()->getY();
breakout->getBall()->setY(paddleY+2);
breakout->getBall()->setX(paddleX-3);
breakout->setDir(4)
int i = 0;
while(i != 3) {
    breakout->simulate_game_step();
}
Boost_test(breakout->getPaddle()->getY() == paddleY+2,
breakout->getPaddle()->getX() == paddleX-3);
}
//*****************************************************************