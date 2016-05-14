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
  int height = walls.size() - 1;
  int width = walls[1].size() - 1;

  int tmp_height = 0;
  int tmp_width = 0;

  std::vector< std::vector< bool > > maze(height);
  /** Loop trough the rows of the tmp vector */
  for (auto& row : maze) {
    std::vector< bool > tmp_row(width);
    for(auto c : walls[tmp_height]){
      if(c == '#'){
        tmp_row[tmp_width] == false;
      }else{
        tmp_row[tmp_width] == true;
      }
      tmp_width++;
    }
    tmp_height++;
    /* replace the row with the tmp row */
    row.swap(tmp_row);
  }
  this->maze.swap(maze);
}

void Labyrinth::print_maze(){
  for (auto y : this->maze){
    for (auto x : y){
      if(x){
        std::cout << "#";
      }else{
        std::cout << "+";
      }
    }
    std::cout << std::endl;
  }

}
/*
Wunschliste für maze Klasse:
- bool is_wall(position) -> liefert bool zurück ob die Position eine Wand ist
- position get_entry() -> liefert position mit eingang zurück
- position get_exit() -> liefert position mit ausgang zurück
*/
bool Labyrinth::is_wall(position){
  if(this->maze[position.y][position.x])

}
