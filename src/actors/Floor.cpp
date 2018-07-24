//
// Created by byzilio on 12.07.18.
//

#include "actors/Floor.h"

void Floor::draw() {
  attron(COLOR_PAIR(1));
  mvaddch(getY(), getX(), getSymbol());
  attroff(COLOR_PAIR(1));
}

void Floor::load(fstream &in) {
  in >> x;
  in >> y;
}
