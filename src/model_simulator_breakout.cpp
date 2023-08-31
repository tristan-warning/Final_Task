#include "model_simulator_breakout.h"
#include <ncurses.h>
#include <stdlib.h>

BreakoutObject::BreakoutObject(double _y, double _x) : x(_x), y(_y) {};

double BreakoutObject::getX() { 
    return x;
};

double BreakoutObject::getY() { 
    return y;
};

void BreakoutObject::setX(double a) {
    x = a;
};

void BreakoutObject::setY(double a) {
    y = a;
};

Paddle::Paddle(double y, double x, int _width=4) : BreakoutObject{y,x}, width(_width) {};
    
int Paddle::getwidth() {
    return width;
};

Ball::Ball(double y, double x, int _speed) : BreakoutObject {y,x}, speed(_speed) {};

int Ball::getSpeed() { 
    return speed; 
};

void Ball::setSpeed(int a){
    speed = a;
};

Block::Block(double y, double x, int _health) : BreakoutObject {y,x}, health(_health) {};

int Block::getHealth() {
    return health;
}

void Block::setHealth(int a){
    health = a;
}

LifeBlock :: LifeBlock(double y, double x, int_health) :  Block {y, x, health}
{

}

BreakoutModel::BreakoutModel() : paddle(2, width / 2), ball(3, width / 2, 1), block1(7 , 20, 1), block2(8, 20, 1), block3(10, 20, 1), block4(11, 20, 1), block5(12, 20, 1), block6(13, 20, 1), block7(15, 20, 1), block8(16, 20, 1), lifeBlock1(9, 20, 2), lifeBlock2(14, 20, 2) {
};

Ball& BreakoutModel::getBall() {
    return ball; 
};
    
Block& BreakoutModel::getBlock1() {
    return block1; 
};

Block& BreakoutModel::getBlock2() {
    return block2; 
};

Block& BreakoutModel::getBlock3() {
    return block3; 
};

Block& BreakoutModel::getBlock4() {
    return block4; 
};

Block& BreakoutModel::getBlock5() {
    return block5; 
};

Block& BreakoutModel::getBlock6() {
    return block6; 
};

Block& BreakoutModel::getBlock7() {
    return block7; 
};

Block& BreakoutModel::getBlock8() {
    return block8; 
};

LifeBlock& BreakoutModel::getLifeBlock1() {
    return lifeBlock1; 
};

LifeBlock& BreakoutModel::getLifeBlock2() {
    return lifeBlock2; 
};

Paddle& BreakoutModel::getPaddle() {
    return paddle; 
};

int BreakoutModel::getPaddleLife() {
    return paddleLife; 
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

    if(ball.getY() == block.getY() - 1  || ball.getY() == block.getY()) { //////////////
        block.setHealth(block.getHealth()-1);
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
        paddleLife--;
        paddleServe = true;
    }

    if(paddleServe) {
        ball.setX(paddle.getY() + 1);
        ball.setY(paddle.getX());
    }

    notifyUpdate();
};

void BreakoutModel::control_paddle(int a)
{
    switch(a) {
        // left
        case 1:
            if(paddle.getX() != width / 2 + 4)
                paddle.setX(paddle.getX() - 1);
            break;
        // right
        case 2:
            if(paddle.getX() != width - 3)
                paddle.setX(paddle.getX() + 1);
            break;
        // start
        case 3:
            if(paddleServe) {
                paddleServe = false;
                dir = 1;
            }
            break;
        // enables autoplay
        case 4:
            if (autoplay == false){
                autoplay = true;
            }
            break;
    }

};