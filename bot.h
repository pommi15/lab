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

#include "direction.h"
#include "position.h"
#include "labyrinth.h"

class Bot
{
public:
  /** Constructor needs the maze */
  Bot(const std::shared_ptr<Labyrinth> maze);
  /** find the exit of the maze */
  virtual void find_exit();

protected:
  std::string type;
  std::string name;
  position current_pos;
  direction facing;
  std::vector<position> history;
  unsigned int step_counter;
  std::shared_ptr<Labyrinth> maze;
  virtual void make_step();
  position calc_coordinates(position pos, const direction& dir) const;
  position calc_coordinates() const;


};
