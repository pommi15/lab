#include "righthand.h"
#include "rlutil.h"

Righthand::Righthand(const std::shared_ptr<Labyrinth> maze) : Righthand(maze, "Righty") {}

Righthand::Righthand(const std::shared_ptr<Labyrinth> maze, std::string name) : Bot(maze, name) {
  this->type = "Righthand";
}

/** make a step */
void Righthand::make_step() {
  direction step;
  position pos = this->current_pos;
  /** wall to the right */
  if (this->wall_to_right(pos, this->facing)) {
    /** wall in front */
    if (this->maze->is_wall(this->calc_coordinates())) {
      /** wall to the left -> cul the sac */
      if (this->wall_to_left(pos, this->facing)) {
        /** turn around */
        step = this->turn_180(this->facing);
      } else {
        /** turn left */
        step = this->turn_left(this->facing);
      }
    } else {
      /** go straight */
      step = this->facing;
    }
  } else {
    /** turn right */
    step = this->turn_right(this->facing);
  }
  this->facing = step;
  this->current_pos = this->calc_coordinates();
  this->history.push_back(this->current_pos);
  ++this->step_counter;
}
/** check if wall to the right */
bool Righthand::wall_to_right(const position& pos, const direction& facing) const {
  return this->maze->is_wall(this->calc_coordinates(pos, this->turn_right(facing)));
}
/** check if wall to the left */
bool Righthand::wall_to_left(const position& pos, const direction& facing) const {
  return this->maze->is_wall(this->calc_coordinates(pos, this->turn_left(facing)));
}
