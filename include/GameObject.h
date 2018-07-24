//
// Created by byzilio on 17.07.18.
//

#ifndef LABYRINTH_GAMEOBJECT_H
#define LABYRINTH_GAMEOBJECT_H

#include <Actor.h>
#include <Engine.h>

class GameObject : public Actor {
 public:
  GameObject(char symbol, int x, int y, int ux, int uy, bool solid, const string &name)
      : Actor(symbol, x, y, ux, uy, solid, name) {}

 public:
  Engine *engine;

  virtual ~GameObject() = default;
};

#endif  // LABYRINTH_GAMEOBJECT_H
