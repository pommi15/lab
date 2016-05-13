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

#include "position.h"

class Bot
{
public:
  Bot();
  //Bot(Irrgarten);

  //void findExit()

private:
  std::string type;
  position current;
  std::vector<position> history;
  unsigned int step_counter;
  //void makeStep();
  //


};
