#include <iostream>
#include "rlutil.h"
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
    std::cout << "Straight" << std::endl;
    step = this->facing;
  } else if (this->is_turn(pos)) {
    std::cout << "Turn" << std::endl;
    step = this->turn_direction(pos);
  } else if (this->is_place(pos)) {
    std::cout << "Place" << std::endl;
    step = this->analyse_place(pos);
  } else if (this->is_cul_de_sac(pos)) {
    std::cout << "Cul de sac" << std::endl;
    step = this->turn_180(this->facing);
  }
  this->facing = step;
  this->current_pos = this->calc_coordinates();
  this->history.push_back(this->current_pos);
  ++this->step_counter;
  std::cout << step_counter << " - x: " << pos.x << " y: " << pos.y << std::endl
            << std::endl;
  rlutil::anykey();
}

direction Tremaux::nearest_free_direction(const position& pos,
                                          direction now_facing) const {
  if (this->maze->is_wall(this->calc_coordinates(pos, now_facing))) {
    now_facing = this->turn_direction(pos, now_facing);
  }
  return now_facing;
}

direction Tremaux::analyse_place(const position& pos) {
  std::string pos_str = pos.to_string();
  direction turn = this->facing;
  std::cout << "place: " << this->places.count(pos_str) << std::endl;
  std::cout << "places: " << this->places.size() << std::endl;
  std::cout << "place: " << pos.x << "  " << pos.y << std::endl;

  if (!this->places.count(pos_str)) {
    this->places[pos_str] = {};
    for (int i = 0; i < 4; ++i) {
      this->places[pos_str][i] = (this->maze->is_wall(this->calc_coordinates(
                                  pos, static_cast<direction>(i)))
                                  ? -1
                                  : 0);
    }
    ++this->places[pos_str][this->turn_180(turn)];

    turn = this->nearest_free_direction(pos, turn);
    std::cout << "dir: " << turn << std::endl;
    ++this->places[pos_str][turn];
  } else {
    std::cout << "north: " << this->places[pos_str][NORTH] << std::endl;
    std::cout << "east:  " << this->places[pos_str][EAST] << std::endl;
    std::cout << "south: " << this->places[pos_str][SOUTH] << std::endl;
    std::cout << "west:  " << this->places[pos_str][WEST] << std::endl;
    if (!this->places[pos_str][this->turn_180(turn)]) {
      std::cout << "yolo: " << std::endl;
      turn = this->turn_180(turn);
      ++this->places[pos_str][turn];
      ++this->places[pos_str][turn];
    } else if (this->places[pos_str][this->turn_180(turn)]) {
      bool found_turn = false;
      for (int i = 0; i < 4; ++i) {
        if (this->places[pos_str][i] != -1 && !this->places[pos_str][i]) {
          turn = static_cast<direction>(i);
          found_turn = true;
          break;
        }
      }
      if (!found_turn) {
        for (int i = 0; i < 4; ++i) {
          if (this->places[pos_str][i] == 1) {
            turn = static_cast<direction>(i);
            found_turn = true;
            break;
          }
        }
      }
      if(!found_turn)
        std::cout << "uh shit: " << std::endl;
      ++this->places[pos_str][this->turn_180(turn)];
      ++this->places[pos_str][turn];
    }
  }
  return turn;
}
