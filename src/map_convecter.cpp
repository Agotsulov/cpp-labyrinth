//
// Created by byzilio on 11.07.18.
//

#include <fstream>
#include <string>

using namespace std;

/*
 * Превращяет квадраную удобную карту в карту для игры.
 * !РАСТАВЛЯЕТ ТОЛЬКО ПОЗИЦИЮ НЕ ЗАВИСИМО ОТ ТОГО ЧТО ЗА СИМВОЛ!
 * Кроме _ это пустота(пробел)
 * Все остальное все равно человеку писать.
 */

int main(int argc, char* argv[]) {
  ifstream in;
  ofstream out;

  in.open(argv[1]);
  out.open(argv[2]);

  int w;
  int h;

  in >> w;
  in >> h;

  char c;

  for(int i = 0;i < h;i++){
    for(int j = 0;j < w;j++){
      in >> c;
      if(c != '_') {
        if (!((c == '.') || (c == '#')))
          out << '.' << " " << j << " " << i << endl;
        out << c << " " << j << " " << i << endl;
      }
    }
  }

  in.close();
  return 0;
}