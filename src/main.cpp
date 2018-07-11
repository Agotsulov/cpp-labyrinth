#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>
#include <ncurses.h>
#include <ctime>
#include <chrono>
#include <algorithm>

using namespace std;

void load_level(string &filename);
void load_level(const char * filename);
void create();
void update_actors();
void move_actors();
void collide_actors();
void render_actors();
int get_delta();
void end();

class Actor;
class RoguelikePlayer;
class Coin;
class Door;

int input;

int delta;

int row, col;

bool version = false;

int time_passed = 0;
int time_left = 10;
int steps_left = 10;

vector<Actor*> actors; 

class Actor{
 private:
  char symbol;
  bool alive = true;
 protected:
  int x = 0;
  int y = 0;
  int ux = 0;
  int uy = 0;
  bool solid = false;
  string name; //Имя вообще не обязательно. Можно было по символу смотреть. И вообще оно нужно для Block1 Block2...
 public:
  Actor(int x, int y, char symbol, const string &name) : x(x), y(y), symbol(symbol),name(name) {}

  Actor(int x, int y, const string &name) : x(x), y(y),name(name) {}

  Actor(char symbol, int x, int y, bool isSolid, const string &name)
      : symbol(symbol), x(x), y(y), solid(isSolid), name(name) {}

  virtual void update() = 0;
  //Вообще бы эти методы тоже в отдельные классы ,ну для этой игры они нужны почти всем и так проще

  virtual void collide(Actor *other) = 0;

  virtual void draw() = 0;

  virtual void load(fstream &in) = 0;

  bool isAlive(){
      return alive;
  }

  void setAlive(bool alive_){
      alive = alive_;
  }

  void kill(){
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

class Block : public Actor {
 public:
  Block() : Actor('#', 0, 0, true, "Block") {
      setSolid(true);
  }

  void update(){

  }

  void collide(Actor *other){

  }

  void draw(){
      mvaddch(getY(), getX(), getSymbol());
  }

  void load(fstream &in){
      in >> x;
      in >> y;
  }
};

class Floor : public Actor {
 public:
  Floor() : Actor(0, 0, '.', "Floor") {}

  void update(){

  }

  void collide(Actor *other){

  }

  void draw(){
    attron(COLOR_PAIR(1));
    mvaddch(getY(), getX(), getSymbol());
    attroff(COLOR_PAIR(1));
  }

  void load(fstream &in){
      in >> x;
      in >> y;
  }
};

class Coin : public Actor {
 public:
  Coin() : Actor(0, 0, '$', "Coin") {}

  void update(){

  }

  void collide(Actor *other){

  }

  void draw(){
    attron(COLOR_PAIR(2));
    mvaddch(getY(), getX(), getSymbol());
    attroff(COLOR_PAIR(2));
  }

  void load(fstream &in){
      in >> x;
      in >> y;
  }
};

class RoguelikePlayer : public Actor {//Чтобы исправить баг с счетом ходьбы даже в стене нужно запоминать пред позицию. Нахуй надо
public:
    RoguelikePlayer() : Actor(0, 0, '@', "Player") {}

    void update(){
        if(steps_left > 0){
            if(input == 'w'){
                uy = -1;
                steps_left--;
            }
            if(input == 'a'){
                ux = -1;
                steps_left--;
            }
            if(input == 's'){
                uy = 1;
                steps_left--;
            }
            if(input == 'd'){
                ux = 1;
                steps_left--;
            }
        } else {
            load_level(*(new string("lose.txt"))); //обожаю плюсовые костыли OLDVERSION
        }
        if(input == 'r'){
            load_level("start.txt");
        }
    }

    void collide(Actor *other){
        if(other->getSymbol() == '$'){
            other->setAlive(false);
            steps_left += 3;
        }
    }

    void draw(){

      attron(COLOR_PAIR(3));
      mvaddch(getY(), getX(), getSymbol());
      attroff(COLOR_PAIR(3));

      mvprintw(row - 1,0,"Steps left: %i",steps_left);
    }

    void load(fstream &in){
        in >> x;
        in >> y;
    }
};

class RealtimePlayer : public Actor {
 private:
  int mil_sec = 0;
  int dir = 0;
 public:
  RealtimePlayer() : Actor(0, 0, '@', "Player") {
    time_passed = 0;
  }

  void update(){
    if(get_delta() >= 33){ //Так как update вызывается всегда, иначе пришлось бы пистать более сложный ввод
      mil_sec++;
      if(mil_sec >= 30){
        mil_sec = 0;
        time_left--;
        time_passed++;
      }
    }
    if(input == 'w')
      dir = 1;
    if(input == 'a')
      dir = 2;
    if(input == 's')
      dir = 3;
    if(input == 'd')
      dir = 4;


    if(dir == 1)
      uy = -1; //Они обнуляются на каждый тик
    if(dir == 2)
      ux = -1;
    if(dir == 3)
      uy = 1;
    if(dir == 4)
      ux = 1;

    if(input == 'r')
      load_level("start.txt");
    if(time_left <= 0)
      load_level("realtime/end.txt");
  }

  void collide(Actor *other){
      if(other->getSymbol() == '$'){
          other->setAlive(false);
          time_left += 3;
      }
  }

  void draw(){
    attron(COLOR_PAIR(3));
    mvaddch(getY(), getX(), getSymbol());
    attroff(COLOR_PAIR(3));
    mvprintw(row - 2, 0, "Time left:%i ", time_left);
    mvprintw(row - 1, 0, "Time passed:%i ", time_passed);
  }

  void load(fstream &in){
      in >> x;
      in >> y;
  }
};

class Door : public Actor {
 private:
  string level_name;
 public:
  Door() : Actor(0, 0, '>', "Door") {}

  void update(){

  }

  void collide(Actor * other){
      if(other->getName().compare("Player") == 0){
          load_level(level_name);
      }
  }

  void draw(){
      mvaddch(getY(), getX(), getSymbol());
  }

  void load(fstream &in){
      in >> x;
      in >> y;
      in >> level_name;
  }

};

class LeaderBoard : public Actor {
 private:
  string filename;
  string player_name = "";
  struct info{
    string name;
    int score;
  };
  vector<info *> players;
  const int count_of_players = 10;
  bool isWrite = false;
 public:
  LeaderBoard() : Actor(0, 0, 'L', "LeaderBoard") {}

  void update(){
    if(!isWrite) {
      if (input != 10) {
        if (input > 'A' && input < 'z')
          player_name += input;
      } else {
        info *i = new info;

        if(player_name.compare("") != 0)
          i->name = player_name;
        else
          i->name = "lox";

        if(version) //Это такой косяк ну настрать тут include конченый и надо нормальную архитектуру писать а не бегом все делать
          i->score = time_passed;
        else
          i->score = steps_left;
        players.push_back(i);

        info *buff;

        for (int g = 0; g < players.size(); g++) {
          for (int j = 0; j < players.size() - g - 1; j++) {
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

  void collide(Actor *other){

  }

  void draw(){
    if(isWrite) {
      for (int i = 0; i < count_of_players; i++) {
        info *inf = players[i];
        mvprintw(i, 0, "%s    %i    ", inf->name.c_str(), inf->score);
      }
    } else {
      mvprintw(0 ,0, "Enter name: %s ", player_name.c_str());
    }
  }

  void load(fstream &in){
      in >> filename;
      in >> isWrite;

      fstream fin;

      fin.open(filename);

      for(int i = 0;i < count_of_players;i++){
          info * inf = new info;
          fin >> inf->name;
          fin >> inf->score;
          players.push_back(inf);
      }
  }
};

class Choose : public Actor {
 public:
  Choose() : Actor(0, 0, '!', "Choose") {}

  void update(){
    if(input == '1'){
      version = true;
      load_level("realtime/map.txt");
    } else if(input == '2') {
      version = false;
      load_level("roguelike/lab1.txt");
    } else if(input == '3'){
      version = true;
      load_level("realtime/watchOnly.txt");
    } else if(input == '4') {
      version = false;
      load_level("roguelike/watchOnly.txt");
    }
  }

  void collide(Actor *other){

  }

  void draw(){
      mvprintw(0, 0, "Choose version:\n1 - Realtime\n2 - Roguelike\n3 - LeaderBoard Realtime\n4 - LeaderBoard Roguelike");
  }

  void load(fstream &in){
      in >> x;
      in >> y;
  }
};

class Text : public Actor {
 private:
  string text;
 public:
  Text() : Actor(0, 0, 'T', "Text") {}

  void update(){

  }

  void collide(Actor *other){

  }

  void draw(){
    mvprintw(getY(), getX(), text.c_str());
  }

  void load(fstream &in){
    in >> x;
    in >> y;
    in >> text;
  }
};

class CoinGenerator : public Actor {
 private:
  int frequency;
  int mil_sec = 0;
 public:
  CoinGenerator() : Actor(10000, 10000, 'T', "Text") {}

  void update(){
    mil_sec++;
    if(mil_sec >= frequency){
      int pos_x = 0;
      int pos_y = 0;
      while(pos_x == 0){
        int i = rand() % actors.size();
        if(actors[i]->getSymbol() == '.'){
          pos_x = actors[i]->getX();
          pos_y = actors[i]->getY();
        }
      }
      Actor *actor = new Coin;
      actor->setX(pos_x);
      actor->setY(pos_y);
      actors.push_back(actor);
      mil_sec = 0;
    }
  }

  void collide(Actor *other){

  }

  void draw(){

  }

  void load(fstream &in){
    in >> frequency;
  }
};



void create(){
  initscr();

  input = ' ';

  srand (time(NULL));

  noecho();
  nodelay(stdscr, TRUE);
  curs_set(0);

  keypad(stdscr, true);

  start_color();
  init_pair(1,COLOR_CYAN,COLOR_BLACK);
  init_pair(2,COLOR_YELLOW,COLOR_BLACK);
  init_pair(3,COLOR_GREEN,COLOR_BLACK);

  getmaxyx(stdscr, row, col);
}

void load_level(const char * filename){
    fstream in;

    string buff("levels/"); //C++ the best -_-
    buff += filename;

    in.open(buff);

    int count;

    in >> count;

    actors.clear();


    for(int i = 0;i < count;i++){
        Actor * actor = 0x0;
        char curr = 0;
        in >> curr;

        if(curr == '#'){ //Ну можно от этого избавится. Но в С++ нет динамической загрузки. Ради такой маленькой игры делать словарь?
            actor = new Block;
        }
        if(curr == '.'){
            actor = new Floor;
        }
        if(curr == '<'){
            actor = new RoguelikePlayer;
        }
        if(curr == 'r'){
            actor = new RealtimePlayer;
        }
        if(curr == '>'){
            actor = new Door;
        }
        if(curr == '$'){
            actor = new Coin;
        }
        if(curr == '!'){
            actor = new Choose;
        }
        if(curr == 'L') {
          actor = new LeaderBoard;
        }
        if(curr == 'T') {
          actor = new Text;
        }
        if(curr == 'C') {
          actor = new CoinGenerator;
        }

        if(actor != 0x0){
            actor->load(in);
            actors.push_back(actor);
        }

    }
    in.close();
}

void load_level(string &filename){
    load_level(filename.c_str());
}

int get_delta(){
  return delta;
}

int main() {
    create();

    load_level("start.txt");

    cout << actors.size() << endl;

    std::chrono::time_point<std::chrono::system_clock> last_update, curr;

    curr = chrono::system_clock::now();
    last_update = chrono::system_clock::now();

    while(true){
      curr = chrono::system_clock::now();

      delta = static_cast<int>(std::chrono::duration_cast<std::chrono::milliseconds>
          (curr-last_update).count());

      update_actors(); //update тут так как надо писать нормльный input

      if(delta >= 33){
        last_update = chrono::system_clock::now();


        move_actors();
        collide_actors();

        render_actors(); //Это лучше не вытаскивать иначе видно как перерисовывает
      }
      input = getch();

      if(input == KEY_BACKSPACE)
        break;
      if(input == ' ') {
        time_left = 10;
        steps_left = 10;
        load_level("start.txt");
      }
    }

    end();
}

void update_actors(){
    for(int i = 0;i < actors.size();i++){
        if(actors[i]->isAlive()) 
            actors[i]->update();
    }
}

void move_actors(){
    for(int i = 0;i < actors.size();i++){
        if(actors[i]->isAlive()){
            Actor * a = actors[i];
            int new_x = a->getX() + a->getUx();
            int new_y = a->getY() + a->getUy();

            for(int c = 0;c < actors.size();c++){

                if(i != c)
                    if((new_x == actors[c]->getX()) && (new_y == actors[c]->getY()))
                        if(!actors[c]->isSolid()){
                        a->setX(new_x);
                        a->setY(new_y);
                }
            }
        }
    }
}

void collide_actors(){
    //Может быть ситуация когда кто то кого то подвигатет.
    //Все короче лечится множеством пар сталкиваемых актеров.
    for(int i = 0;i < actors.size();i++){
        for(int j = 0;j < actors.size();j++) {
            Actor *a1 = actors[i];
            Actor *a2 = actors[j];
            if ((a1->isAlive()) && (a2->isAlive()) && a1->getX() == a2->getX() && a1->getY() == a2->getY()){
                a1->collide(a2);
            }
        }
    }
    for(int i = 0;i < actors.size();i++){ //Да это можно вытащить в разные методы.
        if(actors[i]->isAlive()){
            Actor * a = actors[i];
            a->setUx(0);
            a->setUy(0); // Лучше обнулять после collide ,иначе на момент collide Actor не знает с какой стороны столкнулись
        }
    }
}

void render_actors(){
    clear();

    for(int i = 0; i < actors.size();i++)
        if(actors[i]->isAlive())
            actors[i]->draw();

    refresh();
}

void end(){
    endwin();

    //for(int i = 0;i < actors.size();i++)
    //    cout << endl << actors[i]->getSymbol() << " " << actors[i]->getX() << " " << actors[i]->getY();

    actors.clear();
}
