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
#include "tremaux.h"
#include "namegen.h"
#include "gaston.h"

int main(int argc, char* argv[]) {
  std::string filepath = argv[1];
  auto import = std::make_shared<Import>();
  auto converted = import->convert(filepath);
  auto laby = std::make_shared<Labyrinth>(converted);
  auto namegen = std::make_shared<Namegen>();

  auto bot = std::make_shared<Gaston>(laby, namegen->get_name());

  std::cout << "Entry at: x: " << laby->get_entry().x << " y: " << laby->get_entry().y << std::endl;
  std::cout << "Exit at: x: " << laby->get_exit().x << " y: " << laby->get_exit().y << std::endl;

  std::cout << "            1111111111222222222233333333334444444444555555555566666666666" << std::endl;
  std::cout << "  01234567890123456789012345678901234567890123456789012345678901234567890" << std::endl;

  laby->print_maze();
  bot->find_exit();
  std::cout << namegen->get_name() << std::endl;
  return 0;
}
