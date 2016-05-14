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
#include <fstream>

class Labyrinth {
public:
  Labyrinth(std::vector<std::string> walls);
  void print_maze();
private:
  std::vector<std::vector<bool>> maze;

};
