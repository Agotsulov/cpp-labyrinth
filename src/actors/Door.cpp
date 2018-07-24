//
// Created by byzilio on 12.07.18.
//

#include "actors/Door.h"

void Door::collide(Actor *other) {
  if (other->getSymbol() == '@') {
    engine->change_level(level_name);
  }
}
void Door::load(fstream &in) {
  in >> x;
  in >> y;
  in >> level_name;
}
void Door::draw() {
  mvaddch(getY(), getX(), getSymbol());
}
