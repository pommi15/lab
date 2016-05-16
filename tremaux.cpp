#include "tremaux.h"

Tremaux::Tremaux(const std::shared_ptr<Labyrinth> maze) : Bot(maze) {
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

bool Tremaux::is_straight(const position& pos) const {
  return !this->maze->is_wall(this->calc_coordinates(pos, this->facing));
}

bool Tremaux::is_turn(const position& pos) const {
  bool north = !this->maze->is_wall(this->calc_coordinates(pos, NORTH));
  bool east = !this->maze->is_wall(this->calc_coordinates(pos, EAST));
  bool south = !this->maze->is_wall(this->calc_coordinates(pos, SOUTH));
  bool west = !this->maze->is_wall(this->calc_coordinates(pos, WEST));
  return (north + east + south + west) == 2;
}

bool Tremaux::is_place(const position& pos) const {
  bool north = !this->maze->is_wall(this->calc_coordinates(pos, NORTH));
  bool east = !this->maze->is_wall(this->calc_coordinates(pos, EAST));
  bool south = !this->maze->is_wall(this->calc_coordinates(pos, SOUTH));
  bool west = !this->maze->is_wall(this->calc_coordinates(pos, WEST));
  return (north + east + south + west) > 2;
}

bool Tremaux::is_cul_de_sac(const position& pos) const {
  bool north = this->maze->is_wall(this->calc_coordinates(pos, NORTH));
  bool east = this->maze->is_wall(this->calc_coordinates(pos, EAST));
  bool south = this->maze->is_wall(this->calc_coordinates(pos, SOUTH));
  bool west = this->maze->is_wall(this->calc_coordinates(pos, WEST));
  return (north + east + south + west) == 3;
}

direction Tremaux::turn_180(const direction& dir) const {
  return static_cast<direction>((dir + 2) % 4);
}

direction Tremaux::turn_right(const direction& dir) const {
  return static_cast<direction>((dir + 1) % 4);
}

direction Tremaux::turn_left(const direction& dir) const {
  return static_cast<direction>((dir - 1) % 4);
}

direction Tremaux::turn_direction(const position& pos) const {
  direction right = this->turn_right(this->facing);
  direction left = this->turn_left(this->facing);
  if (!this->maze->is_wall(this->calc_coordinates(pos, right))) {
    return right;
  } else {
    return left;
  }
}
