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

/** righthand algorithm */
class Righthand : public Bot {
  void make_step();
  /** check if wall is to the right */
  bool wall_to_right(const position& pos, const direction& facing) const;
  /** check if wall is to the left */
  bool wall_to_left(const position& pos, const direction& facing) const;
 public:
  /** ctor */
  Righthand(const std::shared_ptr<Labyrinth> maze);
  Righthand(const std::shared_ptr<Labyrinth> maze, std::string name);
};
