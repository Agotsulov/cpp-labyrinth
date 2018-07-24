//
// Created by byzilio on 12.07.18.
//

#ifndef LABYRINTH_ROGUELIKEPLAYER_H
#define LABYRINTH_ROGUELIKEPLAYER_H

#include <GameObject.h>

class RoguelikePlayer : public GameObject {
 public:
  RoguelikePlayer();

  void create() {}

  void update();

  void collide(Actor *other);

  void draw();

  void load(fstream &in);
};

#endif  // LABYRINTH_ROGUELIKEPLAYER_H
