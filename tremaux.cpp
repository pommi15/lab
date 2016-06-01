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
    step = this->facing;
  } else if (this->is_turn(pos)) {
    step = this->turn_direction(pos);
  } else if (this->is_place(pos)) {
    step = this->analyse_place(pos);
  } else if (this->is_cul_de_sac(pos)) {
    step = this->turn_180(this->facing);
  }
  this->facing = step;
  this->current_pos = this->calc_coordinates();
  this->history.push_back(this->current_pos);
  ++this->step_counter;
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
    ++this->places[pos_str][turn];
  } else {
    /** Platz bekannt, Hinweg unbekannt -> umdrehen */
    if (!this->places[pos_str][this->turn_180(turn)]) {
      /** Turn 180 degrees */
      turn = this->turn_180(turn);
      /** Increment the number of visits by 2 - once for entering and once for
       * exiting */
      this->places[pos_str][turn] += 2;
    }
    /** Platz bekannt, Hinweg bekannt */
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
          /** Foun a place with only one mark */
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
       * THIS SHOULD DEFINITLY NOT HAPPEN
       */
      if (!found_turn) {
        std::cerr << this->name << ":" << std::endl;
        std::cerr << "I didn't find a valid turn. Is the maze compromised?"
                  << std::endl
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
