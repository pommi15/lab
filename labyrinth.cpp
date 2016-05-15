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
  print_maze();
  maze_entries();
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
void Labyrinth::maze_entries(){
  this->entry_set = false;
  this->exit_set = false;
  /* north wall is checked for entry and exit */
  for (int i = 0; i < width; ++i ){
    if(this->entry_set){
      if(this->maze[0][i]){
        this->exit.y = 0;
        this->exit.x = i;
        this->exit_set = true;
        break;
      }
    }else{
      if(this->maze[0][i]){
        this->entry.y = 0;
        this->entry.x = i;
        this->entry_set = true;

      }
    }
  }

  /* if exit isn't set yet, the south wall is checked */
  if(!this->exit_set){
    for (int i = 0; i < width; ++i){
      if(this->entry_set){
        if(this->maze[this->height-1][i]){
          this->exit.y = this->height;
          this->exit.x = i;
          this->exit_set = true;
          break;
        }
      }else{
        if(this->maze[this->height-1][i]){
          this->entry.y = this->height;
          this->entry.x = i;
          this->entry_set = true;

        }
      }

    }
  }

  /* if exit isn't set yet, the west wall is chekced */
  if(!this->exit_set){
    for (int i = 0; i < this->height; ++i){

      if(this->entry_set){
        if(this->maze[i][0]){
          this->exit.y = i;
          this->exit.x = 0;
          this->exit_set = true;
          break;
        }
      }else{
        if(this->maze[i][0]){
          this->entry.y = i;
          this->entry.x = 0;
          this->entry_set = true;
        }
      }
    }
  }

  /* if exit isn't set yet, the east wall is chekced */
  if(!this->exit_set){
    for (int i = 0; i < this->height; ++i){
      if(this->entry_set){
        if(this->maze[i][width-1]){
          this->exit.y = i;
          this->exit.x = width;
          this->exit_set = true;
          break;
        }
      }else{
        if(this->maze[i][width-1]){
          this->entry.y = i;
          this->entry.x = width;
          this->entry_set = true;
        }
      }
    }
  }
}

bool Labyrinth::is_wall(position wall){
  if(this->maze[wall.y][wall.x]){
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
