 #define BOOST_TEST_MODULE module_simulater_test

#include <ncurses.h>
#include <stdlib.h>
#include <iostream>

#include "model_simulator_breakout.h"
#include <view_console.h>
#include "controller_console.h"
 
//erstellen eines BreakOut test Objekts
 BreakoutModel* breakout = new BreakoutModel();
 ConsoleView* view = new ConsoleView(breakout);
 ConsoleController* controller = new ConsoleController(breakout);
