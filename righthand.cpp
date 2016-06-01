#include "righthand.h"
#include "rlutil.h"

Righthand::Righthand(const std::shared_ptr<Labyrinth> maze) : Righthand(maze, "Righty") {}

Righthand::Righthand(const std::shared_ptr<Labyrinth> maze, std::string name) : Bot(maze, name) {
  this->type = "Righthand";
  this->origin_dir = this->facing;
}

void Righthand::make_step() {
  direction step;
  position pos = this->current_pos;
  if (this->wall_to_right(pos, this->facing)) {
    if (this->maze->is_wall(this->calc_coordinates())) {
      if (this->wall_to_left(pos, this->facing)) {
        step = this->turn_180(this->facing);
      } else {
        step = this->turn_left(this->facing);
      }
    } else {
      step = this->facing;
    }
  } else {
    step = this->turn_right(this->facing);
  }
  this->facing = step;
  this->current_pos = this->calc_coordinates();
  this->history.push_back(this->current_pos);
  ++this->step_counter;
}

bool Righthand::wall_to_right(const position& pos, const direction& facing) const {
  return this->maze->is_wall(this->calc_coordinates(pos, this->turn_right(facing)));
}

bool Righthand::wall_to_left(const position& pos, const direction& facing) const {
  return this->maze->is_wall(this->calc_coordinates(pos, this->turn_left(facing)));
}
