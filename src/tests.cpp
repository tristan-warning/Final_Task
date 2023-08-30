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



//***************************************************************
//Obere Wand Tests
//***************************************************************

Boost_AUTO_TEST_CASE(case6)
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

Boost_AUTO_TEST_CASE(case7)
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

Boost_AUTO_TEST_CASE(case8)
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

//****************************************************************



//***************************************************************
//Linke Wand Tests
//***************************************************************

Boost_AUTO_TEST_CASE(case9)
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

Boost_AUTO_TEST_CASE(case10)
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

//****************************************************************



//***************************************************************
//Rechte Wand Tests
//***************************************************************

Boost_AUTO_TEST_CASE(case11)
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

Boost_AUTO_TEST_CASE(case12)
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

//****************************************************************



//***************************************************************
//Unteres Spielfeld Test
//***************************************************************

Boost_AUTO_TEST_CASE(case13)
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

//****************************************************************



//***************************************************************
//Block Test
//***************************************************************

//Drei mögliche Treffer oben
Boost_AUTO_TEST_CASE(case14)
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

Boost_AUTO_TEST_CASE(case15)
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

Boost_AUTO_TEST_CASE(case16)
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

//Drei mögliche Treffer Unten
Boost_AUTO_TEST_CASE(case17)
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

Boost_AUTO_TEST_CASE(case18)
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

Boost_AUTO_TEST_CASE(case19)
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

//Zwei mögliche Treffer Links
Boost_AUTO_TEST_CASE(case20)
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

Boost_AUTO_TEST_CASE(case21)
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

//Zwei mögliche Treffer Rechts
Boost_AUTO_TEST_CASE(case22)
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

Boost_AUTO_TEST_CASE(case23)
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

//Verliert der Block Leben?
Boost_AUTO_TEST_CASE(case24)
{

}

//Verschwindet der Block?
Boost_AUTO_TEST_CASE(case25)
{

}

//****************************************************************

