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
#include <memory>
#include <random>
#include "namegen.h"
#include "import.h"
Namegen::Namegen() {
  auto impNames = std::make_shared(Import("botdata/botnames.txt"));
  auto impOrigins = std::make_shared(Import("botdata/botorigin.txt"));
  this->botnames = impNames->input_vector;
  this->botorigins = impOrigins->input_vector;
}

std::string Namegen::get_name() const{
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> names(0, this->botnames.size());
  std::uniform_int_distribution<> origins(0, this->botorigins.size());
  std::string name = this->botnames[names(gen)] + " from " + this->botorigins(origins(gen));
  return name;
}


