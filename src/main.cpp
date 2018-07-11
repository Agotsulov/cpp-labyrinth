#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>
#include <ncurses.h>
#include <ctime>

using namespace std;

const int WIDTH = 50;
const int HEIGHT = 20;

void loadLevels(const char * filename);
void load_level(string &filename);
void create();
void render();
void update();
void end();

class Actor;
class RoguelikePlayer;
class Coin;
class Door;

char **map;
int map_h;
int map_w;

string interface;
char **screen;

int input;

bool isRealTime = false;

vector<Actor*> actors; 

vector<string> levels;
int numberLevel = 0; 

class Actor{
 private:
  char symbol;
  bool alive = true;
 protected:
  int x;
  int y;
  int ux;
  int uy;
  bool isSolid = false;
  string name; //Имя вообще не обязательно. Можно было по символу смотреть. И вообще оно нужно для Block1 Block2...
 public:
  Actor(int x, int y, char symbol, const string &name) : x(x), y(y), symbol(symbol),name(name) {}

  Actor(char symbol, int x, int y, bool isSolid, const string &name)
      : symbol(symbol), x(x), y(y), isSolid(isSolid), name(name) {}

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
  Block() : Actor('#', 0, 0, true, "Block") {}

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
      mvaddch(getY(), getX(), getSymbol());
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
      mvaddch(getY(), getX(), getSymbol());
  }

  void load(fstream &in){
      in >> x;
      in >> y;
  }
};

class RoguelikePlayer : public Actor {
private:
    int countSteps = 10;
public:
    RoguelikePlayer() : Actor(0, 0, '@', "Player") {}

    void update(){
        if(countSteps > 0){
            if((input == 'w') && (map[getX() - 1][getY()] != '#')){
                uy = -1;
            }
            if((input == 'a') && (map[getX()][getY() - 1] != '#')){
                ux = -1;
            }
            if((input == 's') && (map[getX() + 1][getY()] != '#')){
                uy = 1;
            }
            if((input == 'd') && (map[getX()][getY() + 1] != '#')){
                ux = 1;
            }
        } else {
            load_level(*(new string("lose.txt"))); //обожаю плюсовые костыли
        }
        if(input == 'r'){
            numberLevel = 0;
            load_level(levels[numberLevel]);
        }
    }

    void collide(Actor *other){
        if(other->getName().compare("Coin") == 0){
            other->setAlive(false);
            countSteps += 3;
        }
    }

    void draw(){
        mvaddch(getY(), getX(), getSymbol());
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
          numberLevel++;
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



void create(){
    initscr();
    input = ' ';
}

void loadLevels(const char * filename){
    fstream in;

    in.open(filename);

    int size_;

    in >> size_;

    for(int i = 0;i < size_;i++){
        string s;
        in >> s;
        levels.push_back(s);
    }

    in.close();
}

void load_level(string &filename){
    fstream in;

    in.open(filename);

    int count;

    in >> count;

    actors.clear();


    for(int i = 0;i < count;i++){
        Actor * actor = 0x0;
        char curr = 0;
        in >> curr;


        if(curr == '#'){
            actor = new Block;
        }
        if(curr == '.'){
            actor = new Floor;
        }
        if(curr == '<'){
            actor = new RoguelikePlayer;
        }
        if(curr == '>'){
            actor = new Door;
        }
        if(curr == '$'){
            actor = new Coin;
        }

        if(actor != 0x0){
            cout << "ADD" << actor;
            actor->load(in);
            actors.push_back(actor);
        }

    }
    in.close();
}

int main() {
    cout << "Choose version:" << endl;
    cout << "1 - Real-time" << endl;
    cout << "2 - Roguelike" << endl;
    char result = '1';

    cin >> result;
    
    if(result == '1')
        isRealTime = true;
    else 
        isRealTime = false;
        

    create();
    loadLevels("levels.txt");
    load_level(*(new string("lab1.txt")));


    while(true){
        update();
        render();
        input = getch();
        if(input == 'q')
            break;
    }

    end();
}

void end(){
    endwin();
    actors.clear();
}

void update(){
    for(int i = 0;i < actors.size();i++){
        if(actors[i]->isAlive()) 
            actors[i]->update();
    }
}

void move(){
    for(int i = 0;i < actors.size();i++){
        if(actors[i]->isAlive()){
            Actor * a = actors[i];
            int new_x = a->getX() + a->getUx();
            int new_y = a->getY() + a->getUy();

            

            a->setUx(0);
            a->setUy(0); // Лучше обнулять после collide
        }
    }
}

void collide(){
    //Может быть ситуация когда кто то кого то подвигатет.
    //Все короче лечится множеством пар сталкиваемых актеров.
    for(int i = 0;i < actors.size();i++){
        for(int j = 0;j < actors.size();j++) {
            Actor *a1 = actors[i];
            Actor *a2 = actors[j];
            if (a1->isAlive() && a2->isAlive() && a1->getX() == a2->getX() && a1->getY() == a2->getY()){
                a1->collide(a2);
            }
        }
    }
}

void render(){
    clear();

    for(int i = 0; i < actors.size();i++)
        actors[i]->draw();

    refresh();
}