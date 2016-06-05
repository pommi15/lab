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

#include "gaston.h"
#include "direction.h"
#include "rlutil.h"

Gaston::Gaston(const std::shared_ptr<Labyrinth> maze) : Gaston(maze, "Gastony") {}

Gaston::Gaston(const std::shared_ptr<Labyrinth> maze, std::string name) : Bot(maze, name) {
  this->type = "Gaston";
}

void Gaston::make_step() {
  /*  Gaston Rules:
      Mark every you enter with STOP
      If you come to a place, Mark the exit you come from with LAST
      Take the first Exit with NONE or if none is marked NONE take the one
      with LAST
  */

  /* position and direction are stored here */
  direction step = this->facing;
  position pos = this->current_pos;
  /* check to see if the bot is at the maze entry */
  if (pos == this->maze->get_entry()) {
    /* if so its marked STOP */
    this->place_markings[pos.to_string()] = STOP;
  }
  /* if corridor is straight no action is nessecary */
  if (this->is_straight(pos)) {
  /* in a cul de sac, bot is turned around */
  } else if (this->is_cul_de_sac(pos)) {
    step = turn_180(step);

  } else if (this->is_place(pos)) {
    /* if there is nor marking on the place, one is set on entrance */
    if (this->check_place(pos)) {
      this->place_markings[calc_coordinates(pos, turn_180(step)).to_string()] = LAST;
    }
    /* place entrance is marked LAST if place has not been stepped into before */
    step = place_choice(pos);
    this->place_markings[(this->calc_coordinates(pos, step)).to_string()] = STOP;
  /* if the next step is a turn bot is turned into right direction */
  } else if (this->is_turn(pos)) {
    step = this->turn_direction(pos);
  }
  /* facing is changed to step */
  this->facing = step;
  /* position is calculated new with facing and positon */
  this->current_pos = this->calc_coordinates(pos, this->facing);
  this->history.push_back(this->current_pos);
  ++this->step_counter;
}

direction Gaston::place_choice(position pos) {
  direction last = NORTH;
  std::vector<direction> dir = {NORTH, EAST, SOUTH, WEST};
  for (int i = 0; i < 4; ++i) {
    if (this->place_markings[this->calc_coordinates(pos, dir[i]).to_string()] == NONE &&
        !this->maze->is_wall(this->calc_coordinates(pos, dir[i]))) {
      return dir[i];
    } else {
      if (this->place_markings[this->calc_coordinates(pos, dir[i]).to_string()] != NONE) {
        if (this->place_markings[this->calc_coordinates(pos, dir[i]).to_string()] == LAST) {
          last = dir[i];
        }
      }
    }
  }
  return last;
}

/* returns true if no place marking of plae is last */
bool Gaston::check_place(position pos) {
  std::vector<direction> dir = {NORTH, EAST, SOUTH, WEST};
  for (int i = 0; i < 4; ++i) {
    if (this->place_markings[this->calc_coordinates(pos, dir[i]).to_string()] != LAST &&
        this->place_markings[this->calc_coordinates(pos, dir[i]).to_string()] != STOP) {
      this->place_markings[this->calc_coordinates(pos, dir[i]).to_string()] = NONE;
    } else if (this->place_markings[this->calc_coordinates(pos, dir[i]).to_string()] == LAST) {
      return false;
    }
  }
  return true;
}
