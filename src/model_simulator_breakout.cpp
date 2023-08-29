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
   
     /*
     * Ball directions
     *
     * 1 - Right
     * 2 - Left
     * 3 - Right Up
     * 4 - Right down
     * 5 - Left Up
     * 6 - Left down
     *
     */

    // Ball logic
    if(ball.getY() == paddle.getY() + 1 || ball.getY() == paddle.getY()) {
        if(ball.getX() <= paddle.getX() + 2 && ball.getX() >= paddle.getX() - 2) {
            if(ball.getX() >= paddle.getX() - 2 && ball.getX() < paddle.getX())
                dir = 3;
            else if(ball.getX() <= paddle.getX() + 2 && ball.getX() > paddle.getX())
                dir = 4;
            else
                dir = 1;
        }
    }

        if(ball.getY() == block.getY() - 1  || ball.getY() == block.getY()) {
        if(ball.getX() <= block.getX() + 2 && ball.getX() >= block.getX() - 2) {
            if (ball.getX() >= block.getX() - 2 && ball.getX() < block.getX())
                dir = 5;
            else if (ball.getX() <= block.getX() + 2 && ball.getX() > block.getX())
                dir = 6;
            else
                dir = 2;
        }
    }

     if(ball.getY() == height - 2) { ////////////
        if (dir == 6)
            dir = 5;
        else
            dir = 3;
    }

    if(ball.getY() == 1) { ///////////////////
        if(dir == 5)
            dir = 6;
        else
            dir = 4;
    }

    if(ball.getY() == 0) {
        player2Points++;
        player1Serve = true;
    }

    if(ball.getY() == height) {
        paddlePoints++;
        paddleServe = true;
    }

    if(paddleServe) {
        ball.setX(paddle.getY() + 1);
        ball.setY(paddle.getX());
    }

    notifyUpdate();
};

void BreakOutModel::control_paddle(wchar_t ch)
{
    switch(ch) {
        // left
        case goLeft:
            if(paddle.getX() != width / 2 + 4)
                paddle.setX(paddle.getX() - 1);
            break;
        // right
        case goRight:
            if(paddle.getX() != width - 3)
                paddle.setX(paddle.getX() + 1);
            break;
        // spacebar
        case ' ':
            if(paddleServe) {
                paddleServe = false;
                dir = 1;
            }
            break;
    }

};