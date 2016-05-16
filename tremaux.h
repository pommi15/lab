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
#include "labyrinth.h"

class Tremaux : public Bot{
 public:
  Tremaux(const std::shared_ptr<Labyrinth> maze);

};
