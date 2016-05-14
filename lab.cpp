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

#include <iostream>
#include <memory>

#include "import.h"
#include "labyrinth.h"

int main(int argc, char* argv[]) {
  auto import = std::make_shared<Import>(argv[1]);
  auto laby = std::make_shared<Labyrinth>(import->input_vector);
  std::cout << "Entry at: x: " << laby->get_entry().x << " y: " << laby->get_entry().y << std::endl;
  std::cout << "Exit at: x: " << laby->get_exit().x << " y: " << laby->get_exit().y << std::endl;
  laby->print_maze();
  return 0;
}
