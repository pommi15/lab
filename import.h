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
#include <iostream>
#include <vector>


class Import {
 public:
  Import();
  std::vector<std::string> convert(const std::string filepath) const;
  std::vector<std::string> convert(const char* filepath) const;
};
