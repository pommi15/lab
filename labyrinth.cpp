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

#include <string>
#include <iostream>
#include <vector>
#include <fstream>

#include "labyrinth.h"
#include "position.h"

/**
 * Constructor
 */
Labyrinth::Labyrinth(const std::vector<std::string>& walls) {
  /** Height of the maze */
  this->height = walls.size();
  /** width of the maze */
  this->width = walls[0].size() - 1;
  /** create a tmp maze */
  std::vector<std::vector<bool>> tmp_maze(this->height);

  /**
   * Loop through the rows
   */
  for (int y = 0; y < this->height; ++y) {
    std::vector<bool> tmp_row(this->width, true);

    if (walls[y].size() > 2) {
      for (int x = 0; x < this->width; ++x) {
        if (walls[y][x] == '#') {
          tmp_row[x] = false;
        } else if (walls[y][x] == ' ') {
          tmp_row[x] = true;
        }
      }
      tmp_maze[y].swap(tmp_row);
    } else {
      if (y == (this->height - 1)) {
        --this->height;
        tmp_maze.pop_back();
      }
    }
  }
  this->maze.swap(tmp_maze);
}


void Labyrinth::print_maze() {
  for (auto row : this->maze) {
    for (auto cell : row) {
      if (cell) {
        std::cout << " ";
      } else {
        std::cout << "+";
      }
    }
    std::cout << std::endl;
  }
}
