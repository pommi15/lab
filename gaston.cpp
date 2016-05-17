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

Gaston::Gaston(const std::shared_ptr<Labyrinth> maze)
    : Gaston(maze, "Gastony") {}

Gaston::Gaston(const std::shared_ptr<Labyrinth> maze, std::string name)
    : Bot(maze, name) {
  this->type = "Gaston";
}

void Gaston::make_step() {
  direction step = this->facing;
  position pos = this->current_pos;
  if (this->is_cul_de_sac(pos)) {
    step = turn_180(step);
  } else if (this->is_turn(pos)) {
    step = this->turn_direction(pos);
  } else if (this->is_straight(pos)) {
    /* if next ahead is place*/
    if(this->is_place(calc_coordinates())){
      /* tile is checked for makrings */
      if(!this->place_markings.count(pos)){
        this->place_markings[pos] = LAST;
      }
    }
  } else if (this->is_place(pos)) {
    /* place entrance is marked first if place has not been stepped into before*/
    step = place_choice(pos);
    this->place_markings[calc_coordinates()] = STOP;
  }
  this->facing = step;
  this->current_pos = this->calc_coordinates();
  this->history.push_back(this->current_pos);
  ++this->step_counter;
}

direction Gaston::place_choice(position pos){
  std::vector<direction> dir = {NORTH, EAST, SOUTH, WEST};
  for(int i = 0; i < 4; ++i){
    if(this->place_markings.count(this->calc_coordinates(pos, dir[i])) < 1){
      return dir[i];
    }
  }
  for(int i = 0; i < 4; ++i){
    if(this->place_markings[this->calc_coordinates(pos, dir[i])] == LAST){
      return dir[i];
    }
  }
}







//
