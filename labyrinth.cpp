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

Labyrinth::Labyrinth(std::vector<std::string> walls){
  int height = walls.size();
  int width = walls[1].size();

  std::vector<std::vector<bool>> tmp(height + 1);
  /** Loop trough the rows of the tmp vector */
  for (auto& row : tmp) {
    /**
    * Create a tmp row with the entered width plus one
    * for the numbering and fill with dots
    */
    std::vector<bool> tmp_row(width , " ");
    /** replace the row with the tmp row */
    row.swap(tmp_row);
  }
  this->maze.swap(tmp);
  int temp_height = 0;
  int temp_width = 0;
  for (auto i : walls){
    for (char& c : i){
      if(c == '#'){
        maze[temp_width][temp_height] = false;
      }else{
        maze[temp_width][temp_height] = true;
      }
      temp_height++;
    }
    temp_width++;
  }
}
