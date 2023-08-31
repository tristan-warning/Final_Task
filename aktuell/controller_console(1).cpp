#include "controller_console.h"

ConsoleController::ConsoleController(BreakoutModel* model) {
	this->model = model;
};

int ConsoleController::getInput() {
    wchar_t ch = getch();
    if (ch == KEY_LEFT || ch == 'a' ){
        controlKey = 1;
    }
    if (ch == KEY_RIGHT || ch == 'd' ){
        controlKey = 2;
    }
    if (ch == ' ' ){
        controlKey = 3;
    }  
    if (ch == 'p' ){
        controlKey = 4;
    }
    if (ch == 'q'){
        return ch;
    }

    model->control_paddle(controlKey);
    return controlKey;
};
