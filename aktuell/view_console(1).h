#pragma once  // #pragma once directive added to avoid multiple inclusions of header files

#include "observer.h"  // Include Observer header file
#include "model_simulator_breakout.h"  // Include BreakOutgModel header file
#include <ncurses.h>

class ConsoleView : public Observer  // Inheriting from Observer class
{
    BreakoutModel* model;  // Pointer variable of BreakoutModel class

public:
    ConsoleView(BreakoutModel* model);  // Constructor of ConsoleView class

    virtual ~ConsoleView();  // Virtual destructor of ConsoleView class

    void drawPaddle(int y, int x);  // Function to draw the paddle

    void drawBall(double x, double y);  // Function to draw the ball

    void drawBlock(double x, double y); // Function to draw the block
    
    void drawLifeBlock(double x, double y); // Function to draw the lifeblock 

    void update();  // Function to update the screen

private:
    // Textures
    char wallTexture = 'X';  // Wall texture character

    void setup_view();  // Function to set up the view
};
