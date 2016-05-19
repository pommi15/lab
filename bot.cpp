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

Bot::Bot(const std::shared_ptr<Labyrinth> maze) : Bot(maze, "Randy"){};

Bot::Bot(const std::shared_ptr<Labyrinth> maze, std::string name)
    : maze(maze), type("Random"), name(name), step_counter(0) {
  this->current_pos = this->maze->get_entry();
  this->history.push_back(this->current_pos);
  this->facing = SOUTH;
  if (!this->is_straight(this->current_pos)) {
    this->facing = this->turn_180(this->facing);
    if (!this->is_straight(this->current_pos)) {
      this->facing = this->turn_direction(this->current_pos);
    }
  }
}

void Bot::find_exit() {
  position exit = this->maze->get_exit();
  while (this->current_pos != exit) {
    this->make_step();
  }
  unsigned int count = 1;
  for (auto& pos : this->history) {
    std::cout << count++ << "x: " << pos.x << " y: " << pos.y << std::endl;
  }
}

std::string Bot::get_name() {
  return this->name;
}
std::string Bot::get_type() {
  return this->type;
}
unsigned int Bot::get_step_counter() {
  return this->step_counter;
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
    } else {
      first = false;
    }
    pos = this->calc_coordinates();
  } while (this->maze->is_wall(pos));
  this->current_pos = pos;
  this->history.push_back(this->current_pos);
  ++this->step_counter;
}

position Bot::calc_coordinates(position pos, const direction& dir) const {
  switch (dir) {
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

position Bot::calc_coordinates() const {
  return this->calc_coordinates(this->current_pos, this->facing);
}

bool Bot::is_straight(const position& pos) const {
  bool right = this->maze->is_wall(
      this->calc_coordinates(pos, this->turn_right(this->facing)));
  bool left = this->maze->is_wall(
      this->calc_coordinates(pos, this->turn_left(this->facing)));
  return !this->maze->is_wall(this->calc_coordinates(pos, this->facing)) &&
         right && left;
}

bool Bot::is_turn(const position& pos) const {
  bool north = !this->maze->is_wall(this->calc_coordinates(pos, NORTH));
  bool east = !this->maze->is_wall(this->calc_coordinates(pos, EAST));
  bool south = !this->maze->is_wall(this->calc_coordinates(pos, SOUTH));
  bool west = !this->maze->is_wall(this->calc_coordinates(pos, WEST));
  return (north + east + south + west) == 2;
}

bool Bot::is_place(const position& pos) const {
  bool north = !this->maze->is_wall(this->calc_coordinates(pos, NORTH));
  bool east = !this->maze->is_wall(this->calc_coordinates(pos, EAST));
  bool south = !this->maze->is_wall(this->calc_coordinates(pos, SOUTH));
  bool west = !this->maze->is_wall(this->calc_coordinates(pos, WEST));
  return (north + east + south + west) > 2;
}

bool Bot::is_cul_de_sac(const position& pos) const {
  bool north = this->maze->is_wall(this->calc_coordinates(pos, NORTH));
  bool east = this->maze->is_wall(this->calc_coordinates(pos, EAST));
  bool south = this->maze->is_wall(this->calc_coordinates(pos, SOUTH));
  bool west = this->maze->is_wall(this->calc_coordinates(pos, WEST));
  return (north + east + south + west) == 3;
}

direction Bot::turn_180(const direction& dir) const {
  return static_cast<direction>((dir + 2) % 4);
}

direction Bot::turn_right(const direction& dir) const {
  return static_cast<direction>((dir + 1) % 4);
}

direction Bot::turn_left(const direction& dir) const {
  return static_cast<direction>((dir + 3) % 4);
}

direction Bot::turn_direction(const position& pos, const direction &dir) const {
  direction right = this->turn_right(dir);
  direction left = this->turn_left(dir);
  if (!this->maze->is_wall(this->calc_coordinates(pos, right))) {
    return right;
  } else { // TODO Fixx
    return left;
  }
}

direction Bot::turn_direction(const position& pos) const {
  return this->turn_direction(pos, this->facing);
}
