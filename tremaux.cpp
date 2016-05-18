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
    step = this->analyse_place(pos);
  } else if (this->is_cul_de_sac(pos)) {
  }
  this->facing = step;
  this->current_pos = this->calc_coordinates();
  this->history.push_back(this->current_pos);
  ++this->step_counter;
}

direction Tremaux::analyse_place(const position& pos){
  if(!this->places.count(pos)){
    this->places[pos] = {};
    this->places[pos][NORTH] = (this->maze->is_wall(this->calc_coordinates(pos, NORTH)) ? -1 : 0);
    this->places[pos][EAST] = (this->maze->is_wall(this->calc_coordinates(pos, EAST)) ? -1 : 0);
    this->places[pos][SOUTH] = (this->maze->is_wall(this->calc_coordinates(pos, SOUTH)) ? -1 : 0);
    this->places[pos][WEST] = (this->maze->is_wall(this->calc_coordinates(pos, WEST)) ? -1 : 0);
if(!this->is_straight(this->current_pos)){
    this->facing = this->turn_180(this->facing);
    if(!this->is_straight(this->current_pos)){
      this->facing = this->turn_direction(this->current_pos);
    }
  }
  } else {

  }
  return NORTH;
}
