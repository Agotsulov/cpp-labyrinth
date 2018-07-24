//
// Created by byzilio on 12.07.18.
//

#include "actors/CoinGenerator.h"
#include <Engine.h>
#include <actors/Coin.h>

void CoinGenerator::update() {
  mvprintw(engine->terminal_row - 3, 0, " %i ", mil_sec);
  mil_sec++;
  if (mil_sec >= frequency) {
    int pos_x = 0;
    int pos_y = 0;
    while (pos_x == 0) {
      int i = rand_r(&seed) % engine->get_level()->size();
      if (engine->get_level()->get(i)->getSymbol() == '.') {
        pos_x = engine->get_level()->get(i)->getX();
        pos_y = engine->get_level()->get(i)->getY();
      }
    }
    Actor *actor = new Coin;
    actor->setX(pos_x);
    actor->setY(pos_y);
    engine->get_level()->add(actor);
    mil_sec = 0;
  }
}
void CoinGenerator::load(fstream &in) {
  in >> frequency;
}
