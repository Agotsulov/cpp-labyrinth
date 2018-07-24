//
// Created by byzilio on 12.07.18.
//

#ifndef LABYRINTH_REALTIMEPLAYER_H
#define LABYRINTH_REALTIMEPLAYER_H

#include <GameObject.h>

class RealtimePlayer : public GameObject {
 private:
  int mil_sec = 0;
  int dir = 0;

 public:
  RealtimePlayer();

  void create();

  void update();

  void collide(Actor *other);

  void draw();

  void load(fstream &in);
};

#endif  // LABYRINTH_REALTIMEPLAYER_H
