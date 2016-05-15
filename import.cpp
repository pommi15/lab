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

#include "import.h"

/* constructor */
Import::Import() {}

std::vector<std::string> Import::convert(const std::string &filepath) const{
  return this->convert(filepath.c_str());
}

std::vector<std::string> Import::convert(const char* filepath) const{
  std::ifstream file(filepath);
  std::vector<std::string> lines;
  std::string line;
  while (std::getline(file, line)) {
    if (!line.empty()) {
      lines.push_back(line);
    }
  }
  return lines;
}
