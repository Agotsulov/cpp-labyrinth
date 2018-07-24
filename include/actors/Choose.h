//
// Created by byzilio on 12.07.18.
//

#ifndef LABYRINTH_CHOOSE_H
#define LABYRINTH_CHOOSE_H

#include <GameObject.h>

class Choose : public GameObject {
 public:
  Choose() : GameObject('!', 0, 0, 0, 0, false, "Choose") {}

  void create() {}

  void update();

  void collide(Actor *other) {}

  void draw() {
    mvprintw(0, 0, "Choose version:\n1 - Realtime\n2 - Roguelike\n3 - LeaderBoard Realtime\n4 - LeaderBoard Roguelike");
  }

  void load(fstream &in) {
    in >> x;
    in >> y;
  }
};

#endif  // LABYRINTH_CHOOSE_H
