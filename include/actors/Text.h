//
// Created by byzilio on 12.07.18.
//

#ifndef LABYRINTH_TEXT_H
#define LABYRINTH_TEXT_H

#include <GameObject.h>

class Text : public GameObject {
 private:
  string text;

 public:
  Text();

  void create() {}

  void update() {}

  void collide(Actor *other) {}

  void draw();

  void load(fstream &in);
};

#endif  // LABYRINTH_TEXT_H
