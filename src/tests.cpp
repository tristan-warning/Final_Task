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
    i++;
}
Boost_test(breakout->getBall()->getY() == paddleY+2,
breakout->getBall()->getX() == paddleX);
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
    i++;
}
Boost_test(breakout->getball()->getY() == paddleY+2,
breakout->getBall()->getX() == paddleX+2);
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
    i++;
}
Boost_test(breakout->getBall()->getY() == paddleY+2,
breakout->getBall()->getX() == paddleX+3);
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
    i++;
}
Boost_test(breakout->getBall()->getY() == paddleY+2,
breakout->getBall()->getX() == paddleX-3);
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
    i++;
}
Boost_test(breakout->getBall()->getY() == paddleY+2,
breakout->getBall()->getX() == paddleX-3);
}
//*****************************************************************



//***************************************************************
//Obere Wand Tests
//***************************************************************

//Der Ball bewegt sich gerade nach oben und trifft auf die obere
//Wand -> er soll gerade nach unten abprallen
Boost_AUTO_TEST_CASE(case6)
{
BreakoutModel* breakout = new BreakoutModel(); 
breakout->getBall()->setY(21);
breakout->getBall()->setX(20);
breakout->setDir(1)
int i = 0;
while(i != 3) {
    breakout->simulate_game_step();
    i++;
}
Boost_test(breakout->getBall()->getY() == 21,
breakout->getBall()->getX() == 20);
}

//Der Ball bewegt sich nach rechst oben und trifft auf die obere
//Wand -> er soll gerade nach unten rechts abgelenkt werden
Boost_AUTO_TEST_CASE(case7)
{
BreakoutModel* breakout = new BreakoutModel(); 
breakout->getBall()->setY(21);
breakout->getBall()->setX(20);
breakout->setDir(3)
int i = 0;
while(i != 3) {
    breakout->simulate_game_step();
    i++;
}
Boost_test(breakout->getBall()->getY() == 21,
breakout->getBall()->getX() == 25);
}

//Der Ball bewegt sich nach links oben und trifft auf die obere
//Wand -> er soll gerade nach unten links abgelenkt werden
Boost_AUTO_TEST_CASE(case8)
{
BreakoutModel* breakout = new BreakoutModel(); 
breakout->getBall()->setY(21);
breakout->getBall()->setX(20);
breakout->setDir(5)
int i = 0;
while(i != 3) {
    breakout->simulate_game_step();
    i++;
}
Boost_test(breakout->getBall()->getY() == 21,
breakout->getBall()->getX() == 17);
}

//****************************************************************



//***************************************************************
//Linke Wand Tests
//***************************************************************

//Der Ball bewegt sich nach links oben und trifft auf die linke
//Wand -> er soll nach rechts oben abprallen
Boost_AUTO_TEST_CASE(case9)
{
BreakoutModel* breakout = new BreakoutModel(); 
breakout->getBall()->setY(4);
breakout->getBall()->setX(8);
breakout->setDir(5)
int i = 0;
while(i != 3) {
    breakout->simulate_game_step();
    i++;
}
Boost_test(breakout->getBall()->getY() == 4,
breakout->getBall()->getX() == 12);
}

//Der Ball bewegt sich nach links unten und trifft auf die linke
//Wand -> er soll nach rechts unten abprallen
Boost_AUTO_TEST_CASE(case10)
{
BreakoutModel* breakout = new BreakoutModel(); 
breakout->getBall()->setY(4);
breakout->getBall()->setX(8);
breakout->setDir(6)
int i = 0;
while(i != 3) {
    breakout->simulate_game_step();
    i++;
}
Boost_test(breakout->getBall()->getY() == 4,
breakout->getBall()->getX() == 4);
}

//****************************************************************



//***************************************************************
//Rechte Wand Tests
//***************************************************************

//Der Ball bewegt sich nach rechts oben und trifft auf die rechte
//Wand -> er soll nach links oben abprallen
Boost_AUTO_TEST_CASE(case11)
{
BreakoutModel* breakout = new BreakoutModel(); 
breakout->getBall()->setY(8);
breakout->getBall()->setX(37);
breakout->setDir(3)
int i = 0;
while(i != 3) {
    breakout->simulate_game_step();
    i++;
}
Boost_test(breakout->getBall()->getY() == 12,
breakout->getBall()->getX() == 37);
}

//Der Ball bewegt sich nach rechts unten und trifft auf die rechte
//Wand -> er soll nach links unten abprallen
Boost_AUTO_TEST_CASE(case12)
{
BreakoutModel* breakout = new BreakoutModel(); 
breakout->getBall()->setY(8);
breakout->getBall()->setX(37);
breakout->setDir(5)
int i = 0;
while(i != 3) {
    breakout->simulate_game_step();
    i++;
}
Boost_test(breakout->getBall()->getY() == 37,
breakout->getBall()->getX() == 4);
}

//****************************************************************



//***************************************************************
//Unteres Spielfeld Test
//***************************************************************

Boost_AUTO_TEST_CASE(case13)
{
BreakoutModel* breakout = new BreakoutModel(); 
breakout->getBall()->setY(3);
breakout->getBall()->setX(2);
breakout->setDir(2)
int i = 0;
while(i != 3) {
    breakout->simulate_game_step();
    i++;
}
Boost_test(breakout->getBall()->getY() == -1,
);
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

