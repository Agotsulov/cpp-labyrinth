//
// Created by byzilio on 12.07.18.
//

#include <VectorLevel.h>
#include <actors/Block.h>
#include <actors/Choose.h>
#include <actors/Coin.h>
#include <actors/CoinGenerator.h>
#include <actors/Door.h>
#include <actors/Floor.h>
#include <actors/LeaderBoard.h>
#include <actors/RealtimePlayer.h>
#include <actors/RoguelikePlayer.h>
#include <actors/Text.h>

Actor *VectorLevel::get(int index) {
  return actors[index];
}

Actor *VectorLevel::get(string name) {
  for (auto &actor : actors)
    if (actor->getName().compare(name)) return actor;
  return nullptr;
}

void VectorLevel::add(Actor *actor) {
  actors.push_back(actor);
}

void VectorLevel::add(Actor *actor, int index) {
  actors[index] = actor;
}

void VectorLevel::load(string &filename) {
  fstream in;

  string buff("levels/");  // C++ the best -_-
  buff += filename;

  in.open(buff);

  int count;

  in >> count;

  actors.clear();

  for (int i = 0; i < count; i++) {
    Actor *actor = nullptr;
    char curr = 0;
    in >> curr;

    if (curr == '#') {  // Ну можно от этого избавится. Но в С++ нет динамической загрузки. Ради такой маленькой игры
                        // делать словарь?
      actor = new Block;
    }
    if (curr == '.') {
      actor = new Floor;
    }
    if (curr == '<') {
      actor = new RoguelikePlayer;
    }
    if (curr == 'r') {
      actor = new RealtimePlayer;
    }
    if (curr == '>') {
      actor = new Door;
    }
    if (curr == '$') {
      actor = new Coin;
    }
    if (curr == '!') {
      actor = new Choose;
    }
    if (curr == 'L') {
      actor = new LeaderBoard;
    }
    if (curr == 'T') {
      actor = new Text;
    }
    if (curr == 'C') {
      actor = new CoinGenerator;
    }

    if (actor != nullptr) {
      actor->load(in);
      actors.push_back(actor);
    }
  }
  in.close();
}

int VectorLevel::size() {
  return static_cast<int>(actors.size());
}

void VectorLevel::remove(int index) {
  // Заглушка. В векторе удалять по итератору. Тут не пригодилось.
}

void VectorLevel::remove(string &name) {
  // Заглушка.
}

void VectorLevel::clear() {
  for (auto &actor : actors) delete actor;

  actors.clear();
}
