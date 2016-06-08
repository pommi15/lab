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
#include <algorithm>
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
   * Loop through the rows and replace # with false and space chars with true
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
  /** swap the maze with the tmp_maze */
  this->maze.swap(tmp_maze);
  /** find entry and exit */
  maze_entries();
}
/* function to print out the maze */
void Labyrinth::print_maze() const {
  unsigned int count = 0;
  rlutil::saveDefaultColor();
  for (auto row : this->maze) {
    if (count < 10) {
      std::cout << " ";
    }
    std::cout << count++;
    for (auto cell : row) {
      if (cell) {
        rlutil::setBackgroundColor(rlutil::BLACK);
        std::cout << " ";
        rlutil::resetColor();
      } else {
        rlutil::setBackgroundColor(rlutil::GREEN);
        std::cout << " ";
        rlutil::resetColor();
      }
    }
    std::cout << std::endl;
  }
}
/** print out the maze with a highlighted path */
void Labyrinth::print_maze(const std::vector<position>& history) const {
  int count_y = 0;
  int count_x = 0;
  rlutil::saveDefaultColor();
  for (auto row : this->maze) {
    for (auto cell : row) {
      if (cell) {
        position current_pos;
        current_pos.x = count_x;
        current_pos.y = count_y;
        /** check if the current position is in the history */
        if (std::find(history.begin(), history.end(), current_pos) != history.end()) {
          rlutil::setBackgroundColor(rlutil::RED);
          std::cout << " ";
          rlutil::resetColor();
        } else {
          rlutil::setBackgroundColor(rlutil::BLACK);
          std::cout << " ";
          rlutil::resetColor();
        }

      } else {
        rlutil::setBackgroundColor(rlutil::GREEN);
        std::cout << " ";
        rlutil::resetColor();
      }
      ++count_x;
    }
    std::cout << std::endl;
    ++count_y;
    count_x = 0;
  }
}

/* function to look for entry and exit */
void Labyrinth::maze_entries() {
  bool entry_set = false;
  bool exit_set = false;
  /** loop through the maze */
  for (int y = 0; y < height; ++y) {
    for (int x = 0; x < width; ++x) {
      /** check if position is not a wall */
      if (this->maze[y][x]) {
        /** check if current position is on the outside walls */
        if (((y == 0 || (y == height - 1)) && (x != 0 || x != width - 1)) ||
            ((y != 0 || (y != height - 1)) && (x == 0 || x == width - 1))) {
          /** check if entry is set */
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
    /** break out of the loop if everything is found */
    if (entry_set && exit_set) {
      break;
    }
  }
}

/** check if position is a wall or outside the maze */
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
