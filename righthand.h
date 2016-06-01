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

#include "bot.h"
#include "labyrinth.h"
#include "position.h"

class Righthand : public Bot {
  direction origin_dir;
  void make_step();
  bool wall_to_right(const position& pos, const direction& facing) const;
  bool wall_to_left(const position& pos, const direction& facing) const;
 public:
  Righthand(const std::shared_ptr<Labyrinth> maze);
  Righthand(const std::shared_ptr<Labyrinth> maze, std::string name);
};
