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
#include "bot.h"
#include "namegen.h"

Bot::Bot(const std::shared_ptr<Labyrinth> maze) : maze(maze) {
  auto namegen = std::make_shared<Namegen>();
  this->type = "Base";
  this->name = namegen->get_name();
  this->current_pos = this->maze->get_entry();
  this->history.push_back(this->current_pos);
  this->facing = SOUTH;
}

void Bot::find_exit() {
  position exit = this->maze->get_exit();
  while (this->current_pos != exit) {
    this->make_step();
  }
}

void Bot::make_step() {
  bool first = true;
  position pos = this->current_pos;
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(NORTH, WEST);
  do {
    if (!first) {
      this->facing = static_cast<direction>(dis(gen));
    }
    pos = this->calc_coordinates();
  } while (this->maze->is_wall(pos));
  this->current_pos = pos;
  this->history.push_back(this->current_pos);
}

position Bot::calc_coordinates() const {
  position pos = this->current_pos;
  switch (this->facing) {
    case NORTH:
      --pos.y;
      break;
    case EAST:
      ++pos.x;
      break;
    case SOUTH:
      ++pos.y;
      break;
    case WEST:
      --pos.x;
      break;
  }
  return pos;
}
