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
#pragma once

#include <string>
#include <vector>

#include "import.h"

/** namegenerator class */
class Namegen {
 public:
  /** constructor */
  Namegen();
  /** get a random name */
  std::string get_name() const;

 private:
  /** names */
  std::vector<std::string> botnames;
  /** origins */
  std::vector<std::string> botorigins;
  /** adjectives */
  std::vector<std::string> botadjectives;
};
