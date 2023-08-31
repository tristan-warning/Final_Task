#ifndef MODEL_BREAKOUT_H_ // header guard to prevent multiple inclusions of the same header file
#define MODEL_BREAKOUT_H_

#include "observer.h" // include header file for the Observable class

class BreakoutObject {
protected:
    double x, y; // BreakeOutObject's coordinates and height

public:
    BreakoutObject(double y, double x); // constructor that takes in initial x and y coordinates of player
    double getX();
    double getY();
    void setX(double a);
    void setY(double a);
};

class Paddle : public BreakoutObject {
private:
    int width; // paddle's width

public:
    Paddle(double y, double x, int width); // constructor that takes in initial x and y coordinates of paddle
    int getwidth();
};

class Ball : public BreakoutObject {
private:
    int speed; // ball's speed
    
public:
    Ball(double y, double x, int speed); // constructor that takes in initial x and y coordinates of ball and its speed
    int getSpeed();
    void setSpeed(int a);
};

class Block : public BreakoutObject {
protected: 
    int health; // block's health

public:
    Block(double y, double x, int health); // constructor that takes in initial x and y coordinates of block and its health
    int getHealth();
    void setHealth(int a);
};

class LifeBlock :  public Block // constructor that takes in initial x and y coordinates of lifeBlock and its health
{
public:
    LifeBlock(double y, double x, int health);
};

class BreakoutModel : public Observable { // BrakeOutModel class inherits from Observable class
public:
    BreakoutModel(); // constructor

    Ball& getBall();
    Paddle& getPaddle();
    Block& getBlock1();
    Block& getBlock2();
    Block& getBlock3();
    Block& getBlock4();
    Block& getBlock5();
    Block& getBlock6();
    Block& getBlock7();
    Block& getBlock8();
    LifeBlock& getLifeBlock1();
    LifeBlock& getLifeBlock2();
    
    int getGameWidth(); // returns the game's width
    int getGameHeight(); // returns the game's height
    int getPaddleLife(); // returns points

    void simulate_game_step(); // simulates one step of the BreakOut game
    void control_paddle(int a); // updates paddle movement direction

private:
    int width = 40; // game width
    int height = 24; // game height
    int dir = 1; // ball direction
    int paddleLife = 0; // player's Lifes 
    bool paddleServe = false; // flag for serving
    bool autoplay = false; // autoplay is disabled
    Paddle paddle; // player object
    Ball ball; // ball object
    Block block1, block2, block3, block4, block5, block6, block7, block8; // block objects
    LifeBlock lifeBlock1, lifeBlock2; // Lifeblock objects
};

#endif // end of header file
