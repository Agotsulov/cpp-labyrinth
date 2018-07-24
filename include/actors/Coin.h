//
// Created by byzilio on 12.07.18.
//

#ifndef LABYRINTH_COIN_H
#define LABYRINTH_COIN_H

#include <GameObject.h>

class Coin : public GameObject {
 public:
  Coin();

  void create() {}

  void update() {}

  void collide(Actor *other) {}

  void draw();

  void load(fstream &in);
};

#endif  // LABYRINTH_COIN_H
