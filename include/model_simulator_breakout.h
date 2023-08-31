#ifndef MODEL_BREAKOUT_H_ // header guard to prevent multiple inclusions of the same header file
#define MODEL_BREAKOUT_H_

#include "observer.h" // include header file for the Observable class

class BreakeoutObject {
protected:
    double x, y; // BreakeOutObject's coordinates and height

public:
    BreakoutObject(double y, double x); // constructor that takes in initial x and y coordinates of player
    double getX();
    double getY();
    void setX(double a);
    void setY(double a);
};

class Paddle : public BreakeoutObject {
private:
    int width; // paddle's width

public:
    Paddle(double y, double x, int width); // constructor that takes in initial x and y coordinates of paddle
    int getwidth();
};

class Ball : public BreakeoutObject {
private:
    int speed; // ball's speed
    
public:
    Ball(double y, double x, int speed); // constructor that takes in initial x and y coordinates of ball and its speed
    int getSpeed();
    void setSpeed(int a);
};

class Block : public BreakeoutObject {
protected: 
    int health; // block's health

public:
    Block(double y, double x, int health); // constructor that takes in initial x and y coordinates of block and its health
    int getHealth();
    void setHealth(int a);
}

class LifeBlock :  public Block // constructor that takes in initial x and y coordinates of lifeBlock and its health
{
}

class BreakoutModel : public Observable { // BrakeOutModel class inherits from Observable class
public:
    BreakoutModel(); // constructor

    int getGameWidth(); // returns the game's width
    int getGameHeight(); // returns the game's height
    int getPaddlePoints(); // returns points

    void simulate_game_step(); // simulates one step of the BreakOut game
    void control_paddle(int a); // updates paddle movement direction

private:
    int width = 40; // game width
    int height = 24; // game height
    int dir = 1; // ball direction
    int paddleLife = 0; // player's Lifes 
    bool paddleServe = false; // flag for servinsg
    Paddle paddle; // player object
    Ball ball; // ball object
    Block block1, block2, block3, block4, block5, block6, block7, block8; // block objects
    LifeBlock lifeBlock1, lifeBlock2; // Lifeblock objects
};

#endif // end of header file
