#include <Engine.h>

int main() {
  Engine engine("start.txt");

  std::chrono::time_point<std::chrono::system_clock> last_update, curr;

  curr = chrono::system_clock::now();
  last_update = chrono::system_clock::now();

  while (true) {
    curr = chrono::system_clock::now();

    engine.delta = static_cast<int>(std::chrono::duration_cast<std::chrono::milliseconds>(curr - last_update).count());

    engine.input = getch();

    engine.update_actors();  // update тут так как надо писать нормльный input

    if (engine.delta >= engine.length_of_frame) {
      last_update = chrono::system_clock::now();

      engine.move_actors();
      engine.collide_actors();

      engine.render_actors();  // Это лучше не вытаскивать иначе видно как перерисовывает
    }

    if (engine.input == KEY_BACKSPACE) break;
    if (engine.input == ' ') {
      engine.time_left = 10;
      engine.steps_left = 10;
      engine.change_level("start.txt");
    }
  }
}
