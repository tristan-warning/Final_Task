#include "model_simulator_breakout.h"
#include <ncurses.h>
#include <stdlib.h>

BreakOutObject::BreakOutObject(double _y, double _x) : x(_x), y(_y) {};

double BreakOutObject::getX() { 
    return x;
};

double BreakOutObject::getY() { 
    return y;
};

void BreakOutObject::setX(double a) {
    x = a;
};

void BreakOutObject::setY(double a) {
    y = a;
};

Paddle::Paddle(double y, double x, int _width=4) : BreakOutObject{y,x}, width(_width) {};
    
int Paddle::getwidth() {
    return width;
};

Ball::Ball(double y, double x, int _speed) : BreakOutObject {y,x}, speed(_speed) {};

int Ball::getSpeed() { 
    return speed; 
};

void Ball::setSpeed(int a){
    speed = a;
};

Block::Block(double y, double x, int _health) : BreakOutObjects {y,x}, health(_health) {};

int Block::getHealth() {
    return health;
}

void Block::setHealth(int a){
    health = a;
}

BreakoutModel::BreakoutModel() {
};


int BreakoutModel::getGameWidth() {
    return width; 
};
    
int BreakoutModel::getGameHeight() {
    return height; 
};
    

void BreakoutModel::simulate_game_step()
{
    // Implement game dynamics.
    notifyUpdate();
};