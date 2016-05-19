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
#include <map>

#include "bot.h"
#include "position.h"
#include "labyrinth.h"


class Gaston : public Bot{
public:
  Gaston(const std::shared_ptr<Labyrinth> maze);
  Gaston(const std::shared_ptr<Labyrinth> maze, std::string name);
private:
  enum marking : int{LAST, STOP};
  void make_step();
  std::map<position, marking> place_markings;
  direction place_choice(position pos);
};
