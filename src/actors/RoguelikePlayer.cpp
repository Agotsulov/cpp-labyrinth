//
// Created by byzilio on 12.07.18.
//

#include "actors/RoguelikePlayer.h"
#include <string>

RoguelikePlayer::RoguelikePlayer() : GameObject('@', 0, 0, 0, 0, false, "Player") {}

void RoguelikePlayer::collide(Actor *other) {
  if (other->getSymbol() == '$') {
    other->setAlive(false);
    engine->steps_left += 3;
  }
}

void RoguelikePlayer::draw() {
  attron(COLOR_PAIR(3));
  mvaddch(getY(), getX(), getSymbol());
  attroff(COLOR_PAIR(3));

  mvprintw(engine->terminal_row - 1, 0, "Steps left: %i", engine->steps_left);
}

void RoguelikePlayer::update() {
  if (engine->steps_left > 0) {
    if (engine->input == 'w') {
      uy = -1;
      engine->steps_left--;
    }
    if (engine->input == 'a') {
      ux = -1;
      engine->steps_left--;
    }
    if (engine->input == 's') {
      uy = 1;
      engine->steps_left--;
    }
    if (engine->input == 'd') {
      ux = 1;
      engine->steps_left--;
    }
  } else {
    engine->change_level(*(new string("lose.txt")));  // обожаю плюсовые костыли OLDVERSION
  }
}

void RoguelikePlayer::load(fstream &in) {
  in >> x;
  in >> y;
}
