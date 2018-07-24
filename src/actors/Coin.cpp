//
// Created by byzilio on 12.07.18.
//

#include <actors/Coin.h>

Coin::Coin() : GameObject('$', 0, 0, 0, 0, false, "Coin") {}

void Coin::draw() {
  attron(COLOR_PAIR(2));
  mvaddch(getY(), getX(), getSymbol());
  attroff(COLOR_PAIR(2));
}

void Coin::load(fstream &in) {
  in >> x;
  in >> y;
}
