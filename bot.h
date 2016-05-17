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

#pragma once
#include <string>
#include <vector>
#include <memory>

#include "direction.h"
#include "position.h"
#include "labyrinth.h"

class Bot {
 public:
  /** Constructor needs the maze */
  Bot(const std::shared_ptr<Labyrinth> maze);
  Bot(const std::shared_ptr<Labyrinth> maze, std::string name);
  /** find the exit of the maze */
  virtual void find_exit();
  std::string get_name();
  std::string get_type();
  unsigned int get_step_counter();
 protected:
  std::shared_ptr<Labyrinth> maze;
  std::string type;
  std::string name;
  position current_pos;
  direction facing;
  std::vector<position> history;
  unsigned int step_counter;
  virtual void make_step();
  position calc_coordinates(position pos, const direction& dir) const;
  position calc_coordinates() const;
  bool is_place(const position& pos) const;
  bool is_turn(const position& pos) const;
  bool is_straight(const position& pos) const;
  bool is_cul_de_sac(const position& pos) const;
  direction turn_180(const direction& dir) const;
  direction turn_left(const direction& dir) const;
  direction turn_right(const direction& dir) const;
  direction turn_direction(const position& pos) const;
};
