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
#include <string>

#include "import.h"
#include "labyrinth.h"
#include "namegen.h"

int main(int argc, char* argv[]) {
  std::string filepath = argv[1];
  auto import = std::make_shared<Import>();
  auto converted = import->convert(filepath);
  auto laby = std::make_shared<Labyrinth>(converted);
  laby->print_maze();
  auto gen = std::make_shared<Namegen>();
  std::cout << gen->get_name() << std::endl;
  return 0;
}
