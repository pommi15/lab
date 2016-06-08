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

/** constructor if no name is given. calls other constr with default name */
Bot::Bot(const std::shared_ptr<Labyrinth> maze) : Bot(maze, "Randy"){};

Bot::Bot(const std::shared_ptr<Labyrinth> maze, std::string name)
    : maze(maze), name(name), type("Random"), step_counter(0), solved(false) {
  /** place the bot at the entry of the maze */
  this->current_pos = this->maze->get_entry();
  /** save the current position in the history */
  this->history.push_back(this->current_pos);
  /** initial facing south */
  this->facing = SOUTH;
  /** find a direction the bot can look initally */
  /** check if bot can not go this way */
  if (!this->is_straight(this->current_pos)) {
    /** turn around */
    this->facing = this->turn_180(this->facing);
    /** check if bot can not go this way */
    if (!this->is_straight(this->current_pos)) {
      /** turn right or left */
      this->facing = this->turn_direction(this->current_pos);
    }
  }
}

Bot::~Bot(){};

void Bot::find_exit() {
  /** exit of the maze */
  position exit = this->maze->get_exit();
  /** run in a loop until the bot is at the exit */
  while (this->current_pos != exit) {
    /** make a step */
    this->make_step();
  }
  /** bot has solved the maze */
  this->solved = true;
}

std::string Bot::get_name() const {
  return this->name;
}
std::string Bot::get_type() const {
  return this->type;
}

std::vector<position> Bot::get_history() const {
  return this->history;
}

void Bot::print_history() const {
  unsigned int count = 1;
  for (auto& pos : this->history) {
    std::cout << count++ << pos << std::endl;
  }
}

unsigned int Bot::get_step_counter() const {
  return this->step_counter;
}

/**
 * make a step
 * the base class implements a random algorithm which isn't used in production
 */
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

/** calculate the coordinates */
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
/** check if bot can go straight ahead and has walls on both sides */
bool Bot::is_straight(const position& pos) const {
  bool right = this->maze->is_wall(this->calc_coordinates(pos, this->turn_right(this->facing)));
  bool left = this->maze->is_wall(this->calc_coordinates(pos, this->turn_left(this->facing)));
  return !this->maze->is_wall(this->calc_coordinates(pos, this->facing)) && right && left;
}

/** check if current position is a turn */
bool Bot::is_turn(const position& pos) const {
  bool north = !this->maze->is_wall(this->calc_coordinates(pos, NORTH));
  bool east = !this->maze->is_wall(this->calc_coordinates(pos, EAST));
  bool south = !this->maze->is_wall(this->calc_coordinates(pos, SOUTH));
  bool west = !this->maze->is_wall(this->calc_coordinates(pos, WEST));
  /** two ways have to be free */
  return (north + east + south + west) == 2;
}

/** check if bot is at a place  */
bool Bot::is_place(const position& pos) const {
  bool north = !this->maze->is_wall(this->calc_coordinates(pos, NORTH));
  bool east = !this->maze->is_wall(this->calc_coordinates(pos, EAST));
  bool south = !this->maze->is_wall(this->calc_coordinates(pos, SOUTH));
  bool west = !this->maze->is_wall(this->calc_coordinates(pos, WEST));
  /** more than 2 ways have to be free */
  return (north + east + south + west) > 2;
}

/** check if bot is in a cul de sac */
bool Bot::is_cul_de_sac(const position& pos) const {
  bool north = this->maze->is_wall(this->calc_coordinates(pos, NORTH));
  bool east = this->maze->is_wall(this->calc_coordinates(pos, EAST));
  bool south = this->maze->is_wall(this->calc_coordinates(pos, SOUTH));
  bool west = this->maze->is_wall(this->calc_coordinates(pos, WEST));
  /** 3 ways have to be walls */
  return (north + east + south + west) == 3;
}

/** turn 180 degrees */
direction Bot::turn_180(const direction& dir) const {
  return static_cast<direction>((dir + 2) % 4);
}

/** turn right */
direction Bot::turn_right(const direction& dir) const {
  return static_cast<direction>((dir + 1) % 4);
}

/** turn left */
direction Bot::turn_left(const direction& dir) const {
  return static_cast<direction>((dir + 3) % 4);
}

/** turn right or left, check which direction is free */
direction Bot::turn_direction(const position& pos, const direction& dir) const {
  direction right = this->turn_right(dir);
  direction left = this->turn_left(dir);
  if (!this->maze->is_wall(this->calc_coordinates(pos, right))) {
    return right;
  } else {
    return left;
  }
}
/** turn right or left with current facing */
direction Bot::turn_direction(const position& pos) const {
  return this->turn_direction(pos, this->facing);
}

bool Bot::is_solved() const {
  return this->solved;
}
