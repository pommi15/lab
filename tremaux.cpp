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
#include <iostream>
#include <string>
#include "rlutil.h"
#include "tremaux.h"

Tremaux::Tremaux(const std::shared_ptr<Labyrinth> maze) : Tremaux(maze, "Tremauxy") {}

Tremaux::Tremaux(const std::shared_ptr<Labyrinth> maze, std::string name) : Bot(maze, name) {
  this->type = "Tremaux";
}
/** make a step */
void Tremaux::make_step() {
  direction step;
  position pos = this->current_pos;
  /** if straight */
  if (this->is_straight(pos)) {
    /** go this way */
    step = this->facing;
  } else if (this->is_turn(pos)) {
    /** follow the turn */
    step = this->turn_direction(pos);
  } else if (this->is_place(pos)) {
    /** analyse the place */
    step = this->analyse_place(pos);
  } else if (this->is_cul_de_sac(pos)) {
    /** turn around */
    step = this->turn_180(this->facing);
  }
  this->facing = step;
  this->current_pos = this->calc_coordinates();
  this->history.push_back(this->current_pos);
  ++this->step_counter;
}

/** find the nearest free direction */
direction Tremaux::nearest_free_direction(const position& pos, direction now_facing) const {
  /** check if bot can go straight */
  if (this->maze->is_wall(this->calc_coordinates(pos, now_facing))) {
    /** turn left or right */
    now_facing = this->turn_direction(pos, now_facing);
  }
  return now_facing;
}

/** analyse a place */
direction Tremaux::analyse_place(const position& pos) {
  /** current place to string */
  std::string pos_str = pos.to_string();
  direction turn = this->facing;
  /** check if place is visited for the first time */
  if (!this->places.count(pos_str)) {
    /** add the place to the map */
    this->places[pos_str] = {};
    /** find out which ways are walls  */
    for (int i = 0; i < 4; ++i) {
      /** if wall set to -1 else 0 */
      this->places[pos_str][i] =
          (this->maze->is_wall(this->calc_coordinates(pos, static_cast<direction>(i))) ? -1 : 0);
    }
    /** increase the counter for the direction from where bot came */
    ++this->places[pos_str][this->turn_180(turn)];
    /** find the nearest free direction */
    turn = this->nearest_free_direction(pos, turn);
    /** increase the counter for the selected direction */
    ++this->places[pos_str][turn];
  } else {
    /** Place knowen, Way there not -> turn around */
    if (!this->places[pos_str][this->turn_180(turn)]) {
      /** Turn 180 degrees */
      turn = this->turn_180(turn);
      /** Increment the number of visits by 2 - once for entering and once for
       * exiting */
      this->places[pos_str][turn] += 2;
    }
    /** place  knowen, way there also */
    else if (this->places[pos_str][this->turn_180(turn)] > 0) {
      /** Increment number of visits by 1 - entered from there */
      ++this->places[pos_str][this->turn_180(turn)];
      /** no turn found */
      bool found_turn = false;
      /** try to find a way that is not marked */
      for (int i = 0; i < 4; ++i) {
        /** No marking for the place */
        if (this->places[pos_str][i] == 0) {
          /** set the turn to the direction (i) */
          turn = static_cast<direction>(i);
          /** found a turn */
          found_turn = true;
          break;
        }
      }
      /**
       * No turn found -> no unmarked way
       */
      if (!found_turn) {
        /** find way with only one mark */
        for (int i = 0; i < 4; ++i) {
          /** Found a place with only one mark */
          if (this->places[pos_str][i] == 1) {
            /** set the turn to the direction (i) */
            turn = static_cast<direction>(i);
            /** Found a turn */
            found_turn = true;
            break;
          }
        }
      }
      /**
       * No turn found, all ways visited twice
       * THIS SHOULD DEFINITLY NOT HAPPEN and did not in any of the test mazes
       */
      if (!found_turn) {
        std::cerr << this->name << ":" << std::endl;
        std::cerr << "I didn't find a valid turn. Is the maze compromised?" << std::endl
                  << "I will exit now..." << std::endl;
        std::cerr << "(╯°□°）╯︵ ┻━┻" << std::endl;
        exit(EXIT_FAILURE);
      }
      /** Increment the number of visits by 1 - exited that way */
      ++this->places[pos_str][turn];
    }
  }
  return turn;
}
