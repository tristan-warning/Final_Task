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
    mvaddch(y, x + 2, '-');
    mvaddch(y, x + 1, '-');
    mvaddch(y, x, '-');
    mvaddch(y, x - 1, '-');
    mvaddch(y, x - 2, '-');
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
    mvprintw(model->getGameHeight() + 1, model->getGameWidth() / 2 / 2, "player's Life: %i", model->getPaddleLife());

    // Draw different objects. 
    drawBall(model->getBall().getY(), model->getBall().getX());
    drawPaddle(model->getPaddle().getY(), model->getPaddle().getX());
    if(model->getBlock1().getHealth() > 0){   
         drawBlock(model->getBlock1().getY(), model->getBlock1().getX());
         }
    if(model->getBlock2().getHealth() > 0){
         drawBlock(model->getBlock2().getY(), model->getBlock2().getX());
        }
    if(model->getBlock3().getHealth() > 0){
         drawBlock(model->getBlock3().getY(), model->getBlock3().getX());
        }
    if(model->getBlock4().getHealth() > 0){
        drawBlock(model->getBlock4().getY(), model->getBlock4().getX());
        }
    if(model->getBlock5().getHealth() > 0){
         drawBlock(model->getBlock5().getY(), model->getBlock5().getX());
        }
    if(model->getBlock6().getHealth() > 0){
         drawBlock(model->getBlock6().getY(), model->getBlock6().getX());
        }
    if(model->getBlock7().getHealth() > 0){
         drawBlock(model->getBlock7().getY(), model->getBlock7().getX());
        }
    if(model->getBlock8().getHealth() > 0){
         drawBlock(model->getBlock8().getY(), model->getBlock8().getX());
        }
    if(model->getLifeBlock1().getHealth() > 0){
         drawLifeBlock(model->getLifeBlock1().getY(), model->getLifeBlock1().getX());
        }
    if(model->getLifeBlock2().getHealth() > 0){
         drawLifeBlock(model->getLifeBlock2().getY(), model->getLifeBlock2().getX());
        }
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