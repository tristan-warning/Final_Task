#include "view_console.h"
#include <ncurses.h>
#include <stdlib.h>


ConsoleView::ConsoleView(BreakoutModel* model) {
	setup_view();
	this->model = model;
	this->model->addObserver(this);
};

ConsoleView::~ConsoleView() {
    endwin();
};

void ConsoleView::drawPaddle(int y, int x) {
    mvaddch(y + 1, x, '_');
    mvaddch(y, x, '_');
    mvaddch(y - 1, x, '_');
};

void ConsoleView::drawBall(double x, double y) {
    mvaddch(x, y, 'o');
};

void ConsoleView::update() {
    mvaddch(x, y, '#');
}

void ConsoleView::update() {
    // libncurses standard loop calls
    erase();
    refresh();

    // Example for building the game view
    for(int i = 0; i < model->getGameWidth(); i++) {
        mvaddch(0, i, wallTexture);
    }
    for(int i = 0; i < model->getGameHeight(); i++) {
        mvaddch(i, 0, wallTexture);
        mvaddch(i, model->getGameWidth() - 1, wallTexture);
    }

    // Show points of player
    mvprintw(1, model->getGameWidth() / 2 / 2, "%i", model->getPaddleHealth());

    // Draw different objects. 
    drawBall(model->getBall().getY(), model->getBall().getX());
    drawBlock(model->getBlock().getY(), model->getBlock().getX());
    drawPaddle(model->getPaddle().getY(), model->getPaddle().getX());

};

void ConsoleView::setup_view() {
    // Init ncurses
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    timeout(30);
};