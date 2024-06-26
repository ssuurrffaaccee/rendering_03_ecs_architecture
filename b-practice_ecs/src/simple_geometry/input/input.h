#pragma once
enum class GameCommand : unsigned int {
  forward = 1 << 0,                  // W
  backward = 1 << 1,                 // S
  left = 1 << 2,                     // A
  right = 1 << 3,                    // D
  jump = 1 << 4,                     // SPACE
  squat = 1 << 5,                    // not implemented yet
  sprint = 1 << 6,                   // LEFT SHIFT
  fire = 1 << 7,                     // not implemented yet
  free_carema = 1 << 8,              // F
  invalid = (unsigned int)(1 << 31)  // lost focus
};
class Window;
class World;
extern unsigned int k_complement_control_command;

class Input {
 public:
  void onKey(int key, int scancode, int action, int mods);
  void onCursorPos(double current_cursor_x, double current_cursor_y);

  void initialize(Window* window, World* world);
  void update();
  void clear();

  int cursor_delta_x_{0};
  int cursor_delta_y_{0};

  float cursor_delta_yaw_{0};
  float cursor_delta_pitch_{0};

  void resetGameCommand() { m_game_command = 0; }
  unsigned int getGameCommand() const { return m_game_command; }

 private:
  unsigned int m_game_command{0};

  int last_cursor_x_{0};
  int last_cursor_y_{0};
  Window* window_;
  World* world_;
};
