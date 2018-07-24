//
// Created by byzilio on 12.07.18.
//

#include <Engine.h>
#include <GameObject.h>
#include <VectorLevel.h>

Engine::Engine(string first_level) {
  initscr();

  level = new VectorLevel;

  input = ' ';

  noecho();
  nodelay(stdscr, TRUE);
  curs_set(0);

  keypad(stdscr, true);

  start_color();
  init_pair(1, COLOR_CYAN, COLOR_BLACK);
  init_pair(2, COLOR_YELLOW, COLOR_BLACK);
  init_pair(3, COLOR_GREEN, COLOR_BLACK);

  getmaxyx(stdscr, terminal_row, terminal_col);

  change_level(first_level);
}

void Engine::update_actors() {
  for (int i = 0; i < level->size(); i++) {
    if (level->get(i)->isAlive()) level->get(i)->update();
  }
}

void Engine::move_actors() {
  for (int i = 0; i < level->size(); i++) {
    if (level->get(i)->isAlive()) {
      Actor *a = level->get(i);
      int new_x = a->getX() + a->getUx();
      int new_y = a->getY() + a->getUy();

      for (int c = 0; c < level->size(); c++) {
        if (i != c)
          if ((new_x == level->get(c)->getX()) && (new_y == level->get(c)->getY()))
            if (!level->get(c)->isSolid()) {
              a->setX(new_x);
              a->setY(new_y);
            }
      }
    }
  }
}

void Engine::collide_actors() {
  // Может быть ситуация когда кто то кого то подвигатет.
  // Все короче лечится множеством пар сталкиваемых актеров.
  for (int i = 0; i < level->size(); i++) {
    for (int j = 0; j < level->size(); j++) {
      Actor *a1 = level->get(i);
      Actor *a2 = level->get(j);
      if ((a1->isAlive()) && (a2->isAlive()) && a1->getX() == a2->getX() && a1->getY() == a2->getY()) {
        a1->collide(a2);
      }
    }
  }
  for (int i = 0; i < level->size(); i++) {  // Да это можно вытащить в разные методы.
    if (level->get(i)->isAlive()) {
      Actor *a = level->get(i);
      a->setUx(0);
      a->setUy(0);  // Лучше обнулять после collide ,иначе на момент collide Actor не знает с какой стороны столкнулись
    }
  }
}

void Engine::render_actors() {
  clear();

  for (int i = 0; i < level->size(); i++)
    if (level->get(i)->isAlive()) level->get(i)->draw();

  refresh();
}

void Engine::change_level(string name) {
  level->load(name);

  for (int i = 0; i < level->size(); i++) {
    GameObject *o =
        dynamic_cast<GameObject *>(level->get(i));  // Это единственый способ избавится тут от циклической зависимости.
    o->engine = this;                               // Это же ОЧЕНЬ медленно плюсы говно.
  }

  for (int i = 0; i < level->size(); i++) level->get(i)->create();
}

int Engine::get_delta() {
  return delta;
}

ILevel *Engine::get_level() {
  return level;
}

Engine::~Engine() {
  endwin();

  // for (int i = 0; i < level->size(); i++) delete level->get(i);

  level->clear();

  delete level;
}
