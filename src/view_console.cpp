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
    mvaddch(y + 2, x, '_');
    mvaddch(y + 1, x, '_');
    mvaddch(y, x, '_');
    mvaddch(y - 1, x, '_');
    mvaddch(y - 2, x, '_';)
};

void ConsoleView::drawBall(double x, double y) {
    mvaddch(x, y, 'o');
};

void ConsoleView::drawBlock(double x, double y) {
    mvaddch(x, y, '#');
}

void ConsoleView::drawLifeBlock(double x, double y) {
    mvaddch(x, y, '+');
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

    // Show player's health
    mvprintw(1, model->getGameWidth() / 2 / 2, "%i", model->getPaddleLife());

    // Draw different objects. 
    drawBall(model->getBall().getY(), model->getBall().getX());
    drawPaddle(model->getPaddle().getY(), model->getPaddle().getX());
    drawBlock1(model->getBlock1().getY(), model->getBlock1().getX());
    drawBlock2(model->getBlock2().getY(), model->getBlock2().getX());
    drawBlock3(model->getBlock3().getY(), model->getBlock3().getX());
    drawBlock4(model->getBlock4().getY(), model->getBlock4().getX());
    drawBlock5(model->getBlock5().getY(), model->getBlock5().getX());
    drawBlock6(model->getBlock6().getY(), model->getBlock6().getX());
    drawBlock7(model->getBlock7().getY(), model->getBlock7().getX());
    drawBlock8(model->getBlock8().getY(), model->getBlock8().getX());
    drawLifeBlock1(model->getLifeBlock1().getY(), model->getLifeBlock1().getX());
    drawLifeBlock2(model->getLifeBlock2().getY(), model->getLifeBlock2().getX());
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