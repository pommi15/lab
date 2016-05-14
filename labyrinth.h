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
<<<<<<< HEAD
  Labyrinth(std::vector<std::string> walls);
  void print_maze();
private:
  std::vector<std::vector<bool>> maze;
=======
  Labyrinth(const std::vector<std::string> &walls);


  void print_maze();
private:
  std::vector<std::vector<bool>> maze;
  position entry;
  position exit;
  int width;
  int height;
>>>>>>> 9a5720eec3db497ecb12b86cf0dd07917ffdcea6

};
