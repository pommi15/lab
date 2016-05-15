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
#include <random>
#include "gaston_bot.h"
#include "namegen.h"

Right_hand_bot::Bot(const std::shared_ptr<Labyrinth> maze) : maze(maze) {
  auto namegen = std::make_shared<Namegen>();
  this->type = "Base";
  this->name = namegen->get_name();
  this->current_pos = this->maze->get_entry();
  this->history.push_back(this->current_pos);
  this->facing = SOUTH;
}

void Right_hand_bot::find_exit() {
  position exit = this->maze->get_exit();
  while (this->current_pos != exit) {
    this->make_step();
  }
  unsigned int count = 1;
  for(auto &pos : this->history) {
    std::cout << count++ << "x: " << pos.x << " y: " << pos.y << std::endl;
  }
}

void Right_hand_bot::make_step() {
  bool first = true;
  position pos = this->current_pos;

  do {
    if (!first) {
      this->facing = static_cast<direction>(dis(gen));
    } else {
      first = false;
    }
    pos = this->calc_coordinates();
  } while (this->maze->is_wall(pos));
  this->current_pos = pos;
  this->history.push_back(this->current_pos);
  ++this->step_counter;
}
