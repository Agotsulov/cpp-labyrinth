//
// Created by byzilio on 12.07.18.
//

#ifndef LABYRINTH_DOOR_H
#define LABYRINTH_DOOR_H

#include <GameObject.h>

class Door : public GameObject {
 private:
  string level_name;

 public:
  Door() : GameObject('>', 0, 0, 0, 0, false, "Door") {}

  void create() {}

  void update() {}

  void collide(Actor *other);

  void draw();

  void load(fstream &in);
};

#endif  // LABYRINTH_DOOR_H
