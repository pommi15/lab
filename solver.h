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
#include <memory>
#include <vector>
#include "labyrinth.h"
#include "bot.h"

/** solver class */
class Solver {
  /** path to maze */
  std::string filepath;
  /** maze */
  std::shared_ptr<Labyrinth> laby;
  /** 3 bots */
  std::vector<std::shared_ptr<Bot>> bots;
  /** graphic mode  */
  bool graphic;
  /** load the maze */
  void load_maze();
  /** setup the bots */
  void setup_bots(bool right, bool tremaux, bool gaston);
 public:
  /** ctor */
  Solver(std::string filepath, bool right, bool tremaux, bool gaston, bool graphic);
  /** solve the maze */
  void solve();
  /** print the maze */
  void print_maze() const;
  /** print the result */
  void print_result() const;
};
