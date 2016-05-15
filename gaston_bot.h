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
#include "bot.h"
#include "direction.h"
#include "position.h"
#include "labyrinth.h"

class Right_hand_bot : public Bot{
public:
  /** Constructor needs the maze */
  Bot(const std::shared_ptr<Labyrinth> maze);
private:
  virtual void make_step();
};
