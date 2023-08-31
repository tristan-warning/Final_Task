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

LifeBlock::LifeBlock(double y, double x, int health) :  Block {y, x, health}
{

}

BreakoutModel::BreakoutModel() : paddle(height - 1, width / 2), ball(height - 2, width / 2, 1), block1(4 , 13, 1), block2(4, 14, 1), block3(4, 15, 1), block4(4, 19, 1), block5(4, 20, 1), block6(4, 24, 1), block7(4, 25, 1), block8(4, 26, 1), lifeBlock1(4, 17, 2), lifeBlock2(4, 22, 2) {
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
     * 1 - up
     * 2 - down
     * 3 - Right Up
     * 4 - Right down
     * 5 - Left Up
     * 6 - Left down
     *
     */

   // Ball logic
    if (ball.getY() == paddle.getY() + 1 || ball.getY() == paddle.getY())
    { // Der Ball trifft auf das Paddle
        if (ball.getX() <= paddle.getX() + 2 && ball.getX() >= paddle.getX() - 2)
        {
            if (ball.getX() >= paddle.getX() - 2 && ball.getX() < paddle.getX())
                dir = 3;
            else if (ball.getX() <= paddle.getX() + 2 && ball.getX() > paddle.getX())
                dir = 4;
            else
                dir = 1;
        }
    }

    /*
    if (ball.getY() == block.getY())
    { // Der Ball trifft auf einen Block
        block.setHealth(block.getHealth() - 1);
        if (dir == 1)
            dir = 2;
        else if (dir == 2)
            dir = 1;
        else if (dir == 3)
            dir = 4;
        else if (dir == 4)
            dir = 3;
        else if (dir == 5)
            dir = 6;
        else
            dir = 5;
    }
*/
    if (ball.getY() == 1)
    { //Der Ball trifft auf das obere Ende des Spielfeldes
        if (dir == 1)
            dir = 2;
        else if (dir == 3)
            dir = 4;
        else
            dir = 6;
    }

    if (ball.getX() == 1)
    { //Der Ball trifft auf den linken Spielfeldrand
        if (dir == 5)
            dir = 3;
        else
            dir = 4;
    }

    if (ball.getX() == width - 1)
    { //Der Ball trifft auf den rechten Spielfeldrand
        if (dir == 3)
            dir = 5;
        else
            dir = 6;
    }

    if (ball.getY() == 0)
    { //Der Ball überschreitet das untere Ende des Spielfeldes
        paddleLife--;
        paddleServe = true;
    }

    if (paddleServe)
    {
        ball.setX(paddle.getY() + 1);
        ball.setY(paddle.getX());
    }

    
     // Ball directions
    if(!paddleServe) {
        if(dir == 1)
            ball.setY(ball.getY() + 1);
        if(dir == 2)
            ball.setY(ball.getY() - 1);

        if(dir == 3) {
            ball.setX(ball.getX() + 1);
            ball.setY(ball.getY() - 0.25);
        }
        if(dir == 4) {
            ball.setX(ball.getX() + 1);
            ball.setY(ball.getY() + 0.25);
        }
        if(dir == 5) {
            ball.setX(ball.getX() - 1);
            ball.setY(ball.getY() - 0.25);
        }
        if(dir == 6) {
            ball.setX(ball.getX() - 1);
            ball.setY(ball.getY() + 0.25);
        }
    }

    
    if(autoplay){
        if(ball.getY() > paddle.getY()) {
            paddle.setY(paddle.getY() + 1);
        }
        else {
            paddle.setY(paddle.getY() -1);
        }
    }
    

    notifyUpdate();
};

void BreakoutModel::control_paddle(int a)
{
    switch(a) {
        // left
        case 1:
            if(paddle.getX() != 4)
                paddle.setX(paddle.getX() - 1);
            break;
        // right
        case 2:
            if(paddle.getX() != width - 4)
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
            if (autoplay){
                autoplay = false;
            }
            else {
                autoplay = true;
            }
            break;
    }

};