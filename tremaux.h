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
#include <map>
#include <array>
#include <memory>

#include "bot.h"
#include "labyrinth.h"
#include "position.h"

class Tremaux : public Bot {
  std::map<position, std::array<int, 4>> places;
  void make_step();
  direction analyse_place(const position &pos);

 public:
  Tremaux(const std::shared_ptr<Labyrinth> maze);
  Tremaux(const std::shared_ptr<Labyrinth> maze, std::string name);
};
