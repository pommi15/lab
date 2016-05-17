/*************************
 *       d[ o_0 ]b       *
 *  the lab - experiment *
 *          by           *
 *    Thomas RAUHOFER    *
 *        if15b029       *
 *          and          *
 *     Tobias WATZEK     *
 *        if15b038       *
 *************************/

#include "gaston_bot.h"

Gaston::Gaston(const std::shared_ptr<Labyrinth> maze)
    : Gaston(maze, "Tremauxy") {}

Gaston::Gaston(const std::shared_ptr<Labyrinth> maze, std::string name)
    : Gaston(maze, name) {
  this->type = "Tremaux";
}

void Gaston::make_step() {
  direction step = this->facing;
  position pos = this->current_pos;
  if (this->is_cul_de_sac(pos)) {
    step = turn_180(step);
  } else if (this->is_turn(pos)) {
    step = this->turn_direction(pos);
  } else if (this->is_place(pos)) {

  } else if () {
  }
  this->facing = step;
  this->current_pos = this->calc_coordinates();
  this->history.push_back(this->current_pos);
  ++this->step_counter;
}
