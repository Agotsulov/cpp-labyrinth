//
// Created by byzilio on 12.07.18.
//

#ifndef LABYRINTH_LEVEL_H
#define LABYRINTH_LEVEL_H

#include <Actor.h>
#include <string>

class ILevel {
 public:
  virtual Actor *get(string name) = 0;

  virtual Actor *get(int index) = 0;

  virtual void add(Actor *actor) = 0;

  virtual void add(Actor *actor, int index) = 0;

  virtual void remove(int index) = 0;

  virtual void remove(string &name) = 0;

  virtual int size() = 0;

  virtual void load(string &filename) = 0;

  virtual void clear() = 0;

  virtual ~ILevel() = default;
};

#endif  // LABYRINTH_LEVEL_H
