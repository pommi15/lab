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
  this->find_entry_and_exit();
}
/* function to print out the maze */
void Labyrinth::print_maze() {
  for (auto row : this->maze) {
    for (auto cell : row) {
      if (cell) {
        std::cout << " ";
      } else {
        std::cout << "#";
      }
    }
    std::cout << std::endl;
  }
}
/* function to look for entry and exit */
void Labyrinth::find_entry_and_exit(){
  int height = this->height;
  int width = this->width;
  this->entry_set = false;
  this->exit_set = false;
  int tmp_height = 0;
  int tmp_width = 0;
  /* north wall is checked for entry and exit */
  for (auto x : this->maze[0]){
    if(this->entry_set){
      if(!x){
        this->exit.y = 0;
        this->exit.x = tmp_width;
        this->exit_set = true;
        std::cout << "tmp_height " << tmp_height<< std::endl;
        break;
      }
    }else{
      if(!x){
        this->entry.y = 0;
        this->entry.x = tmp_width;
        this->entry_set = true;
      }
    }
    tmp_width++;
  }
  /* if exit isn't set yet, the south wall is checked */
  if(!this->exit_set){
    tmp_width = 0;
    for (auto x : this->maze[height]){
      if(this->entry_set){
        if(!x){
          this->exit.y = height;
          this->exit.x = tmp_width;
          this->exit_set = true;
          std::cout << "tmp_height " << tmp_height<< std::endl;
          break;
        }
      }else{
        if(!x){
          this->entry.y = height;
          this->entry.x = tmp_width;
          this->entry_set = true;
        }
      }
      tmp_width++;
    }
  }
  /* if exit isn't set yet, the west wall is chekced */
  if(!this->exit_set){
    tmp_height = 0;
    for (auto x : this->maze){
      if(this->entry_set){
        if(!x[0]){
          this->exit.y = tmp_height;
          this->exit.x = 0;
          this->exit_set = true;
          std::cout << "tmp_height " << tmp_height<< std::endl;
          break;
        }
      }else{
        if(!x[0]){
          this->entry.y = tmp_height;
          this->entry.x = 0;
          this->entry_set = true;
        }
      }
      tmp_height++;
    }
  }
  /* if exit isn't set yet, the east wall is chekced */
  if(!this->exit_set){
    tmp_height = 0;
    for (auto x : this->maze){
      if(this->entry_set){
        if(!x[width]){
          this->exit.y = tmp_height;
          this->exit.x = width;
          this->exit_set = true;
          std::cout << "tmp_height " << tmp_height<< std::endl;
          break;
        }
      }else{
        if(!x[width]){
          this->entry.y = tmp_height;
          this->entry.x = width;
          this->entry_set = true;
        }
      }
      tmp_height++;
    }
  }
  std::cout << "tmp_height " << tmp_height<< std::endl;
}
bool Labyrinth::is_wall(position position){
  if(this->maze[position.y][position.x]){
    return false;
  }else{
    return true;
  }
}

position Labyrinth::get_entry(){
  return this->entry;
}
position Labyrinth::get_exit(){
  return this->exit;
}
