//
// Created by byzilio on 12.07.18.
//

#include "actors/RealtimePlayer.h"

RealtimePlayer::RealtimePlayer() : GameObject('@', 0, 0, 0, 0, false, "Player") {}

void RealtimePlayer::update() {
  if (engine->get_delta() >=
      engine->length_of_frame) {  // Так как update вызывается всегда, иначе пришлось бы пистать более сложный ввод
    mil_sec++;
    if (mil_sec >= engine->FPS) {
      mil_sec = 0;
      engine->time_left--;
      engine->time_passed++;
    }
  }
  if (engine->input == 'w') dir = 1;
  if (engine->input == 'a') dir = 2;
  if (engine->input == 's') dir = 3;
  if (engine->input == 'd') dir = 4;

  if (dir == 1) uy = -1;  // Они обнуляются на каждый тик
  if (dir == 2) ux = -1;
  if (dir == 3) uy = 1;
  if (dir == 4) ux = 1;

  if (engine->time_left <= 0) engine->change_level("realtime/end.txt");
}

void RealtimePlayer::collide(Actor *other) {
  if (other->getSymbol() == '$') {
    other->setAlive(false);
    engine->time_left += 3;
  }
}

void RealtimePlayer::load(fstream &in) {
  in >> x;
  in >> y;
}

void RealtimePlayer::draw() {
  attron(COLOR_PAIR(3));
  mvaddch(getY(), getX(), getSymbol());
  attroff(COLOR_PAIR(3));
  mvprintw(engine->terminal_row - 2, 0, "Time left:%i ", engine->time_left);
  mvprintw(engine->terminal_row - 1, 0, "Time passed:%i ", engine->time_passed);
}

void RealtimePlayer::create() {}
