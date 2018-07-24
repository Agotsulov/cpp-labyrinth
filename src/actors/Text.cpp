//
// Created by byzilio on 12.07.18.
//

#include "actors/Text.h"

Text::Text() : GameObject('T', 0, 0, 0, 0, false, "Text") {}

void Text::draw() {
  mvprintw(getY(), getX(), text.c_str());
}

void Text::load(fstream &in) {
  in >> x;
  in >> y;
  in >> text;
}