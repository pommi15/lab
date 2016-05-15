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
#include <iostream>
#include <vector>
#include "position.h"


class Labyrinth {
public:
  Labyrinth(const std::vector<std::string> &walls);
  void print_maze();
  position get_entry();
  position get_exit();
  bool is_wall(const position &pos);
private:
  void maze_entries();
  position entry;
  position exit;
  bool entry_set;
  bool exit_set;
  std::vector<std::vector<bool>> maze;
  int width;
  int height;
};
