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

/** labyrinth class */
class Labyrinth {
public:
  /** constructor takes vector of strings */
  Labyrinth(const std::vector<std::string> &walls);
  /** print the maze */
  void print_maze() const;
  /** print the maze with a highlighted path */
  void print_maze(const std::vector<position> &history) const;
  /** get the entry */
  position get_entry();
  /** get the exit */
  position get_exit();
  /** check if position is wall or out of the maze */
  bool is_wall(const position &pos);
private:
  /** find entry and exit of the maze */
  void maze_entries();
  position entry;
  position exit;
  std::vector<std::vector<bool>> maze;
  int width;
  int height;
};
