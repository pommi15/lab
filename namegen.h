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

class Namegen
{
public:
  Namegen();
  std::string get_name() const;
private:
  std::vector<std::string> botnames;
  std::vector<std::string> botorigins;
  std::vector<std::string> botadjectives;

};
