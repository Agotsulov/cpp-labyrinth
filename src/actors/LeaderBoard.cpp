//
// Created by byzilio on 12.07.18.
//

#include "actors/LeaderBoard.h"

void LeaderBoard::update() {
  if (!isWrite) {
    if (engine->input != 10) {
      if (engine->input > 'A' && engine->input < 'z' && player_name.length() <= 10) player_name += engine->input;
    } else {
      info *i = new info;

      if (player_name.compare("") != 0)
        i->name = player_name;
      else
        i->name = "lox";

      if (engine->version)  // Это такой косяк ну настрать тут include конченый и надо нормальную архитектуру писать,
                            // а не бегом все делать
        i->score = engine->time_passed;
      else
        i->score = engine->steps_left;
      players.push_back(i);

      info *buff;

      for (size_t g = 0; g < players.size(); g++) {
        for (size_t j = 0; j < players.size() - g - 1; j++) {
          if (players[j]->score < players[j + 1]->score) {
            buff = players[j];
            players[j] = players[j + 1];
            players[j + 1] = buff;
          }
        }
      }

      ofstream out(filename);

      for (int j = 0; j < count_of_players; j++) {
        info *inf = players[j];
        out << inf->name << " " << inf->score << endl;
      }

      out.close();

      isWrite = true;
    }
  }
}
void LeaderBoard::draw() {
  if (isWrite) {
    for (int i = 0; i < count_of_players; i++) {
      info *inf = players[i];
      mvprintw(i, 0, "%s    %i    ", inf->name.c_str(), inf->score);
    }
  } else {
    mvprintw(0, 0, "Enter name: %s ", player_name.c_str());
  }
}
void LeaderBoard::load(fstream &in) {
  in >> filename;
  in >> isWrite;

  fstream fin;

  fin.open(filename);

  for (int i = 0; i < count_of_players; i++) {
    info *inf = new info;
    fin >> inf->name;
    fin >> inf->score;
    players.push_back(inf);
  }
}
