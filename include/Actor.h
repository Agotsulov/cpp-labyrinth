//
// Created by byzilio on 12.07.18.
//

#ifndef LABYRINTH_ACTOR_H
#define LABYRINTH_ACTOR_H

#include <fstream>
#include <string>
#include <utility>

using namespace std;

class Actor {
 private:
  char symbol;
  bool alive = true;

 protected:
  int x = 0;
  int y = 0;

  int ux = 0;
  int uy = 0;

  bool solid = false;

  string name;  // Имя вообще не обязательно. Можно было по символу смотреть. И
                // вообще оно нужно для Block1 Block2...
  bool save = false;

 public:
  Actor(char symbol, int x, int y, int ux, int uy, bool solid, string name)
      : symbol(symbol), x(x), y(y), ux(ux), uy(uy), solid(solid), name(std::move(name)) {}

  // Вообще бы эти методы тоже в отдельные классы ,ну для этой игры они нужны
  // почти всем и так проще

  virtual void create() = 0;

  virtual void collide(Actor *other) = 0;

  virtual void draw() = 0;

  virtual void load(fstream &in) = 0;

  virtual void update() = 0;

  virtual ~Actor() = default;

  void doNotDelete() {
    save = true;
  }

  void doDelete() {
    save = false;
  }

  bool isSave() {
    return save;
  }

  bool isAlive() {
    return alive;
  }

  void setAlive(bool alive_) {
    alive = alive_;
  }

  void kill() {
    alive = false;
  }

  bool isSolid() const {
    return solid;
  }

  void setSolid(bool solid) {
    Actor::solid = solid;
  }

  int getUx() const {
    return ux;
  }

  void setUx(int ux) {
    Actor::ux = ux;
  }

  int getUy() const {
    return uy;
  }

  void setUy(int uy) {
    Actor::uy = uy;
  }

  int getX() const {
    return x;
  }

  void setX(int x) {
    Actor::x = x;
  }

  int getY() const {
    return y;
  }

  void setY(int y) {
    Actor::y = y;
  }

  char getSymbol() const {
    return symbol;
  }

  void setSymbol(char symbol) {
    Actor::symbol = symbol;
  }

  const string &getName() const {
    return name;
  }

  void setName(const string &name) {
    Actor::name = name;
  }
};
#endif  // LABYRINTH_ACTOR_H
