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

/**
 * Bot base class
 * Just implements radom for testing purposes
 */
class Bot {
 public:
  /** Constructor needs the maze */
  Bot(const std::shared_ptr<Labyrinth> maze);
  /** constructor accept name */
  Bot(const std::shared_ptr<Labyrinth> maze, std::string name);
  virtual ~Bot();
  /** find the exit of the maze */
  virtual void find_exit();
  std::string get_name() const;
  std::string get_type() const;
  unsigned int get_step_counter() const;
  std::vector<position> get_history() const;
  /** print the history of visited positions */
  void print_history() const;
  /** check if maze is solved */
  bool is_solved() const;
 protected:
  /** ptr to the maze */
  std::shared_ptr<Labyrinth> maze;
  /** name of the bot */
  std::string name;
  /** type of the bot */
  std::string type;
  /** current position of the bot */
  position current_pos;
  /** direction the bot is facing */
  direction facing;
  /** history of visited positions */
  std::vector<position> history;
  /** steps the bot took */
  unsigned int step_counter;
  /** found exit or not */
  bool solved;
  /** make a step called from find_exit */
  virtual void make_step();
  /** calcualte the coordinates on the maze */
  position calc_coordinates(position pos, const direction& dir) const;
  /** calculate the coordinates on the maze of the current position */
  position calc_coordinates() const;
  /** check if position is a place  */
  bool is_place(const position& pos) const;
  /** check if position is a turn */
  bool is_turn(const position& pos) const;
  /** check if position is a straight path */
  bool is_straight(const position& pos) const;
  /** check if position is a cul de sac */
  bool is_cul_de_sac(const position& pos) const;
  /** turn around */
  direction turn_180(const direction& dir) const;
  /** turn left */
  direction turn_left(const direction& dir) const;
  /** turn right */
  direction turn_right(const direction& dir) const;
  /** turn in a free direction with current facing */
  direction turn_direction(const position& pos) const;
  direction turn_direction(const position& pos, const direction &dir) const;
};
