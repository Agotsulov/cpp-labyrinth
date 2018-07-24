//
// Created by byzilio on 12.07.18.
//

#ifndef LABYRINTH_LEADERBOARD_H
#define LABYRINTH_LEADERBOARD_H

#include <GameObject.h>

class LeaderBoard : public GameObject {
 private:
  string filename;
  string player_name = "";
  struct info {
    string name;
    int score;
  };
  vector<info *> players;
  const int count_of_players = 10;
  bool isWrite = false;

 public:
  LeaderBoard() : GameObject('L', 0, 0, 0, 0, false, "LeaderBoard") {}

  void create() {}

  void update();

  void collide(Actor *other) {}

  void draw();

  void load(fstream &in);
};

#endif  // LABYRINTH_LEADERBOARD_H
