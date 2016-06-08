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
  /** importer to get files line by line as vector */
  auto import = std::make_shared<Import>();
  /** get the names */
  this->botnames = import->convert("botdata/botnames.txt");
  /** get the origins */
  this->botorigins = import->convert("botdata/botorigin.txt");
  /** get the adjectives */
  this->botadjectives = import->convert("botdata/botadjectives.txt");
}
/** get a random name */
std::string Namegen::get_name() const {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> names(0, this->botnames.size() - 1);
  std::uniform_int_distribution<> origins(0, this->botorigins.size() - 1);
  std::uniform_int_distribution<> adjectives(0, this->botadjectives.size() - 1);
  std::string name = this->botnames[names(gen)];
  name = name + " the " + this->botadjectives[adjectives(gen)];
  name = name + " from " + this->botorigins[origins(gen)];
  return name;
}
