#include "model_simulator_breakout.h"
#include <ncurses.h>
#include <stdlib.h>

BreakOutObject::BreakOutObject(double _y, double _x)
 : x(_x), y(_y){};

double BreakOutObject::getX()
{
    return x;
};

double BreakOutObject::getY()
{
    return y;
};

void BreakOutObject::setX(double a)
{
    x = a;
};

void BreakOutObject::setY(double a)
{
    y = a;
};

Paddle::Paddle(double y, double x, int _width = 4)
 : BreakOutObject{y, x}, width(_width){};

int Paddle::getwidth()
{
    return width;
};

Ball::Ball(double y, double x, int _speed) {
setY(y);
setX(x);
setSpeed(speed);
};

int Ball::getSpeed()
{
    return speed;
};

void Ball::setSpeed(int a)
{
    speed = a;
};

Block::Block(double y, double x, int _health) {
 setY(y);
 setX(x);
 setHealth(_health);
};

int Block::getHealth()
{
    return health;
}

void Block::setHealth(int a)
{
    health = a;
}

LifeBlock ::LifeBlock(double y, double x, int_health)
{
setY(y);
setX(x);
setHealth(health);
};

BreakoutModel::BreakoutModel()
{ : paddle(width / 2, 2), ball(width / 2, 3, 1), block};

Ball &BreakoutModel::getBall()
{
    return ball;
};

Block &BreakoutModel::getBlock()
{
    return block;
};

Paddle &BreakoutModel::getPaddle()
{
    return paddle;
};

int BreakoutModel::getDir(){
    return dir;
};

void BreakoutModel::setDir(int _dir){
    dir = _dir;
};

int BreakoutModel::getPaddleLife()
{
    return paddleLife;
};

int BreakoutModel::getGameWidth()
{
    return width;
};

int BreakoutModel::getGameHeight()
{
    return height;
};

void BreakoutModel::simulate_game_step()
{
    // Implement game dynamics.

    /*
     * Ball directions
     *
     * 1 - Up
     * 2 - Down
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

    if (ball.getY() == height - 1)
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

    if (ball.getX() == getGameWidth() - 1)
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
    if (!player1Serve || !player2Serve)
    {
        if (dir == 1) // Up
            ball.setX(ball.getY() + 1);

        if (dir == 2) // Down
            ball.setX(ball.getY() - 1);

        if (dir == 3)
        { // Right Up
            ball.setX(ball.getX() + 1);
            ball.setY(ball.getY() - 0.25);
        }
        if (dir == 4)
        { // Right Down
            ball.setX(ball.getX() + 1);
            ball.setY(ball.getY() + 0.25);
        }
        if (dir == 5)
        { // Left Up
            ball.setX(ball.getX() - 1);
            ball.setY(ball.getY() - 0.25);
        }
        if (dir == 6)
        { // Left Down
            ball.setX(ball.getX() - 1);
            ball.setY(ball.getY() + 0.25);
        }
    }

    if (ball.getY() > player1.getY())
    {
        player1.setY(player1.getY() + 1);
    }
    else
    {
        player1.setY(player1.getY() - 1);
    }

    notifyUpdate();
}

void BreakoutModel::control_paddle(int a)
{
    switch (a)
    {
    // left
    case 1:
        if (paddle.getX() != width / 2 + 4)
            paddle.setX(paddle.getX() - 1);
        break;
    // right
    case 2:
        if (paddle.getX() != width - 3)
            paddle.setX(paddle.getX() + 1);
        break;
    // start
    case 3:
        if (paddleServe)
        {
            paddleServe = false;
            dir = 1;
        }
        break;
    // enables autoplay
    case 4:
        if (autoplay == false)
        {
            autoplay = true;
        }
        break;
    }
};