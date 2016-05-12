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
#ifndef LABYRINTH_H_
#define LABYRINTH_H_
#include <string>
#include <iostream>
#include <vector>
#include <fstream>

class Labyrinth {
public:
  Labyrinth(std::vector<std::string> walls);

  std::vector<std::vector<bool>> maze;
};
#endif  // LABYRINTH_H_
