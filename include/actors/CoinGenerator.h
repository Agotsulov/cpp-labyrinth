//
// Created by byzilio on 12.07.18.
//

#ifndef LABYRINTH_COINGENERATOR_H
#define LABYRINTH_COINGENERATOR_H

#include <GameObject.h>

class CoinGenerator : public GameObject {
 private:
  int frequency;
  int mil_sec = 0;

  unsigned int seed = static_cast<unsigned int>(time(nullptr));

 public:
  CoinGenerator() : GameObject('T', 10000, 10000, 0, 0, false, "Text") {}

  void create() {}

  void update();

  void collide(Actor *other) {}

  void draw() {}

  void load(fstream &in);
};

#endif  // LABYRINTH_COINGENERATOR_H
