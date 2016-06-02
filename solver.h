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
#include <array>
#include "labyrinth.h"
#include "bot.h"

class Solver {
  std::string filepath;
  std::shared_ptr<Labyrinth> laby;
  std::array<std::shared_ptr<Bot>, 3> bots;
  bool graphic;
  void load_maze();
  void setup_bots();
 public:
  Solver(std::string filepath, bool graphic);
  void solve();
  void print_maze() const;
  void print_result() const;
};
