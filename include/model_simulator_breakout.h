#ifndef MODEL_BREAKOUT_H_ // header guard to prevent multiple inclusions of the same header file
#define MODEL_BREAKOUT_H_

#include "observer.h" // include header file for the Observable class

class BrakeOutObject {
protected:
    double x, y; // BrakeOutObject's coordinates and height

public:
    BreakOutObject(double y, double x); // constructor that takes in initial x and y coordinates of player
    double getX();
    double getY();
    void setX(double a);
    void setY(double a);
};

class Paddle : public BrakeOutObject {
private:
    int width; // paddle's width

public:
    Paddle(double y, double x, int width); // constructor that takes in initial x and y coordinates of paddle
    int getwidth();
};

class Ball : public BrakeOutObject {
private:
    int speed; // ball's speed
    
public:
    Ball(double y, double x, int speed); // constructor that takes in initial x and y coordinates of ball and its speed
    int getSpeed();
    void setSpeed(int a);
};

class Block : public BrakeOutObject {
private: 
    int health; // block's health

public:
    Block(double y, double x, int health);
    int getHealth();
    void setHealth(int a);
}

class BreakoutModel : public Observable { // BrakeOutModel class inherits from Observable class
public:
    BreakoutModel(); // constructor

    int getGameWidth(); // returns the game's width
    int getGameHeight(); // returns the game's height
    int getPaddlePoints(); // returns points

    void simulate_game_step(); // simulates one step of the BreakOut game
     void control_paddle(wchar_t); // updates paddle movement direction

private:
    int width = 40; // game width
    int height = 24; // game height
    int dir = 1; // ball direction
    int paddlePoints = 0; // player score
    bool paddleServe = false; // flag for serving
    Paddle paddle; // player object
    Ball ball; // ball object
};

#endif // end of header file
