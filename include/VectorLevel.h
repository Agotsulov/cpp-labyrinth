//
// Created by byzilio on 12.07.18.
//

#ifndef LABYRINTH_VECTORLEVEL_H
#define LABYRINTH_VECTORLEVEL_H

#include <ILevel.h>
#include <vector>

class VectorLevel : public ILevel {
 private:
  vector<Actor *> actors;

 public:
  Actor *get(string name) override;

  Actor *get(int index) override;

  void add(Actor *actor) override;

  void add(Actor *actor, int index) override;

  void remove(int index) override;

  void remove(string &name) override;

  int size() override;

  void load(string &filename) override;

  void clear() override;
};

#endif  // LABYRINTH_VECTORLEVEL_H
