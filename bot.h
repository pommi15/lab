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
