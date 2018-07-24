//
// Created by byzilio on 12.07.18.
//

#ifndef LABYRINTH_BLOCK_H
#define LABYRINTH_BLOCK_H

#include <GameObject.h>

class Block : public GameObject {
 public:
  Block() : GameObject('#', 0, 0, 0, 0, true, "Block") {}

  void create() {}

  void update() {}

  void collide(Actor *other) {}

  void draw();

  void load(fstream &in);
};

#endif  // LABYRINTH_BLOCK_H
