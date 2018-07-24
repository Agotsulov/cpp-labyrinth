//
// Created by byzilio on 12.07.18.
//

#include "actors/Block.h"

void Block::draw() {
  mvaddch(getY(), getX(), getSymbol());
}

void Block::load(fstream &in) {
  in >> x;
  in >> y;
}
