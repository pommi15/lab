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
  std::map<position, std::array<position, 4>> places;
  void make_step();
  bool is_place(const position& pos) const;
  bool is_turn(const position& pos) const;
  bool is_straight(const position& pos) const;
  bool is_cul_de_sac(const position& pos) const;
  direction turn_180(const direction& dir) const;
  direction turn_left(const direction& dir) const;
  direction turn_right(const direction& dir) const;
  direction turn_direction(const position& pos) const;

 public:
  Tremaux(const std::shared_ptr<Labyrinth> maze);
};
