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

Gaston::Gaston(const std::shared_ptr<Labyrinth> maze)
    : Gaston(maze, "Gastony") {}

Gaston::Gaston(const std::shared_ptr<Labyrinth> maze, std::string name)
    : Bot(maze, name) {
  this->type = "Gaston";
}

void Gaston::make_step() {


  direction step = this->facing;
  position pos = this->current_pos;
  if(pos == this->maze->get_entry()){
    this->place_markings[pos.to_string()] = STOP;
  }
  if (this->is_straight(pos)) {
    std::cout <<"straight" << this->step_counter << std::endl;
  }else if (this->is_cul_de_sac(pos)) {
    std::cout <<"cds" << this->step_counter << std::endl;
    step = turn_180(step);
  } else if (this->is_place(pos)) {
    /* if there is nor marking on the place, one is set on entrance */
    if(this->check_place(pos)){
      this->place_markings[calc_coordinates(pos, turn_180(step)).to_string()] = LAST;
      std::cout << "Entering the place: " << this->place_markings[this->calc_coordinates(pos, step).to_string()] << std::endl;
    }
    std::cout <<"place" << std::endl;
    /* place entrance is marked LAST if place has not been stepped into before*/
    step = place_choice(pos);
    std::cout << "placefacing: " << step << std::endl;
    this->place_markings[(this->calc_coordinates(pos, step)).to_string()] = STOP;
    std::cout << "Leaving the place, choice on: " << this->place_markings[this->calc_coordinates(pos, step).to_string()] << std::endl;

  }else if (this->is_turn(pos)) {
    std::cout <<"turn" << this->step_counter << std::endl;
    step = this->turn_direction(pos);

  }
  std::cout << "x : " << pos.x << " y : " << pos.y << std::endl;
  std::cout << "facing: " <<step << std::endl;
  std::cout << "----------------------" << std::endl;
  this->facing = step;
  this->current_pos = this->calc_coordinates(pos, this->facing);
  this->history.push_back(this->current_pos);
  ++this->step_counter;
  rlutil::anykey();
}

direction Gaston::place_choice(position pos){
  direction last = NORTH;
  std::vector<direction> dir = {NORTH, EAST, SOUTH, WEST};
  for(int i = 0; i < 4; ++i){
    std::cout << "Facing: " << dir[i] << " Marking: "<< this->place_markings.count(this->calc_coordinates(pos, dir[i]).to_string()) << std::endl;
    if(!this->place_markings.count(this->calc_coordinates(pos, dir[i]).to_string()) && !this->maze->is_wall(this->calc_coordinates(pos, dir[i]))){
      std::cout << "placeface: i = " << dir[i] << std::endl;
      return dir[i];
    }else{
      if(this->place_markings.count(this->calc_coordinates(pos, dir[1]).to_string())){
        if(this->place_markings[this->calc_coordinates(pos, dir[i]).to_string()] == LAST){
          std::cout << "lastface: i = " << dir[i] << std::endl;
          last = dir[i];
        }
      }
    }
  }
  std::cout << "Took the last one " << std::endl;
  std::cout << "++++++++++++++++++++++++++++++"<< std::endl;
  for(auto x : this->place_markings){
    int i = 0;
    std::cout << "Number " << i << " : " << x << std::endl;
    ++i;
  }
  std::cout << "++++++++++++++++++++++++++++++"<< std::endl;
  return last;
}

/* returns true if no place marking of plae is last */
bool Gaston::check_place(position pos){
  std::vector<direction> dir = {NORTH, EAST, SOUTH, WEST};
  for(int i = 0; i < 4; ++i){
    if(this->place_markings.count(this->calc_coordinates(pos, dir[1]).to_string())){
      if(this->place_markings[this->calc_coordinates(pos, dir[i]).to_string()] == LAST){
        return false;
      }
    }
  }
  return true;
}
