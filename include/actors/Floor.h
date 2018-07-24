//
// Created by byzilio on 12.07.18.
//

#ifndef LABYRINTH_FLOOR_H
#define LABYRINTH_FLOOR_H

#include <GameObject.h>

class Floor : public GameObject {
 public:
  Floor() : GameObject('.', 0, 0, 0, 0, false, "Floor") {}

  void create() {}

  void update() {}

  void collide(Actor *other) {}

  void draw();

  void load(fstream &in);
};

#endif  // LABYRINTH_FLOOR_H
