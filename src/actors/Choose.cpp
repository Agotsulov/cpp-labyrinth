//
// Created by byzilio on 12.07.18.
//

#include "actors/Choose.h"

void Choose::update() {
  if (engine->input == '1') {
    engine->version = true;
    engine->change_level("realtime/map.txt");
  } else if (engine->input == '2') {
    engine->version = false;
    engine->change_level("roguelike/lab1.txt");
  } else if (engine->input == '3') {
    engine->version = true;
    engine->change_level("realtime/watchOnly.txt");
  } else if (engine->input == '4') {
    engine->version = false;
    engine->change_level("roguelike/watchOnly.txt");
  }
}
