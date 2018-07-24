//
// Created by byzilio on 12.07.18.
//

#ifndef LABYRINTH_ENGINE_H
#define LABYRINTH_ENGINE_H

class Engine;
class ILevel;

#include <ILevel.h>
#include <ncurses.h>
#include <algorithm>
#include <chrono>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Engine {
 private:
  ILevel *level;

 public:
  int input = 0;

  const int FPS = 30;
  const int length_of_frame = 1000 / FPS;

  int delta;

  int terminal_row, terminal_col;

  bool version = false;

  int time_passed = 0;
  int time_left = 10;
  int steps_left = 10;

 public:
  explicit Engine(string first_level);

  void update_actors();

  void move_actors();

  void collide_actors();

  void render_actors();

  int get_delta();

  ILevel *get_level();

  void change_level(string name);

  ~Engine();
};

#endif  // LABYRINTH_ENGINE_H
