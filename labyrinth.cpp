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
#include "rlutil.h"
/**
 * Constructor
 */
Labyrinth::Labyrinth(const std::vector<std::string>& walls) {
  /** height of the maze */
  this->height = walls.size();
  /** width of the maze */
  this->width = walls[0].size();
  /** create a tmp maze */
  std::vector<std::vector<bool>> tmp_maze(this->height);

  /**
   * Loop through the rows
   */
  for (int y = 0; y < this->height; ++y) {
    std::vector<bool> tmp_row(this->width, true);
    if (walls[y][0] > 2) {
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
  maze_entries();
}
/* function to print out the maze */
void Labyrinth::print_maze() {
  unsigned int count = 0;
  rlutil::saveDefaultColor();
  for (auto row : this->maze) {
    if(count < 10) {
      std::cout << " ";
    }
    std::cout << count++;
    for (auto cell : row) {
      if (cell) {
        rlutil::setColor(rlutil::BROWN);
        std::cout << "\u2591";
        rlutil::resetColor();
      } else {
        rlutil::setColor(rlutil::GREEN);
        std::cout << "\u2588";
        rlutil::resetColor();
      }
    }
    std::cout << std::endl;
  }
}
/* function to look for entry and exit */
void Labyrinth::maze_entries() {
  entry_set = false;
  exit_set = false;
  for (int y = 0; y < height; ++y) {
    for (int x = 0; x < width; ++x) {
      if (this->maze[y][x]) {
        if (((y == 0 || (y == height - 1)) && (x != 0 || x != width - 1)) ||
            ((y != 0 || (y != height - 1)) && (x == 0 || x == width - 1))) {
          if (!entry_set) {
            this->entry.x = x;
            this->entry.y = y;
            entry_set = true;
          } else if (!exit_set) {
            this->exit.x = x;
            this->exit.y = y;
            exit_set = true;
            break;
          }
        }
      }
    }
    if(entry_set && exit_set){
      break;
    }
  }
}

bool Labyrinth::is_wall(const position& pos) {
  if (pos.y < 0 || pos.y >= this->height || pos.x < 0 || pos.x >= this->width) {
    return true;
  }
  return !this->maze[pos.y][pos.x];
}

position Labyrinth::get_entry() {
  return this->entry;
}
position Labyrinth::get_exit() {
  return this->exit;
}
