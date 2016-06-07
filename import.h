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

/** import class */
class Import {
 public:
  /** constructor */
  Import();
  /** get a string filepath and call convert with c_str */
  std::vector<std::string> convert(const std::string &filepath) const;
  /** get a filepath and convert each line to a vector of strings */
  std::vector<std::string> convert(const char* filepath) const;
};
