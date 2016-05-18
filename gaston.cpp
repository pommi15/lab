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
  int tmp;

  if (this->is_straight(pos)) {
    std::cout <<"straight" << this->step_counter << std::endl;
    /* if next ahead is place*/
    if(this->is_place(calc_coordinates())){
      /* tile is checked for markings */
      if(this->place_markings.count(pos) < 1){
        this->place_markings[pos] = LAST;
      }
    }
  }else if (this->is_cul_de_sac(pos)) {
    std::cout <<"cds" << this->step_counter << std::endl;
    if(pos == this->maze->get_entry()){
      this->place_markings[pos] = LAST;
    }else{
      step = turn_180(step);
    }
  } else if (this->is_place(pos)) {

    std::cout <<"place" << this->step_counter << std::endl;
    /* place entrance is marked first if place has not been stepped into before*/
    step = place_choice(pos);
    std::cout << "placefacing: " << step << std::endl;
    if(!this->place_markings.count(this->calc_coordinates(pos, step))){
      this->place_markings[calc_coordinates()] = STOP;
    }
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

  std::cin >> tmp;
}

direction Gaston::place_choice(position pos){
  std::vector<direction> dir = {NORTH, EAST, SOUTH, WEST};
  direction last;
  for(int i = 0; i < 4; ++i){
    if(this->place_markings.count(this->calc_coordinates(pos, dir[i])) == 0){
      std::cout << "1: i = " << i << std::endl;
      return dir[i];
    }else{
      if(this->place_markings[this->calc_coordinates(pos, dir[i])] == LAST){
        last = dir[i];
      }
    }
  }
  return last;
}
