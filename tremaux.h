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

/** tremaux algorithm */
class Tremaux : public Bot {
  /** places the bot visited */
  std::map<std::string, std::array<int, 4>> places;
  void make_step();
  /** analyse a place */
  direction analyse_place(const position& pos);
  /** nearest free way */
  direction nearest_free_direction(const position& pos, direction now_facing) const;

 public:
  Tremaux(const std::shared_ptr<Labyrinth> maze);
  Tremaux(const std::shared_ptr<Labyrinth> maze, std::string name);
};
