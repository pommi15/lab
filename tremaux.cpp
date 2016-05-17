#include "tremaux.h"

Tremaux::Tremaux(const std::shared_ptr<Labyrinth> maze)
    : Tremaux(maze, "Tremauxy") {}

Tremaux::Tremaux(const std::shared_ptr<Labyrinth> maze, std::string name)
    : Bot(maze, name) {
  this->type = "Tremaux";
}

void Tremaux::make_step() {
  direction step;
  position pos = this->current_pos;
  if (this->is_straight(pos)) {
    step = this->facing;
  } else if (this->is_turn(pos)) {
    step = this->turn_direction(pos);
  } else if (this->is_place(pos)) {
  } else if (this->is_cul_de_sac(pos)) {
  }
  this->facing = step;
  this->current_pos = this->calc_coordinates();
  this->history.push_back(this->current_pos);
  ++this->step_counter;
}
