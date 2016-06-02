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

std::vector<std::string> Import::convert(const std::string& filepath) const {
  return this->convert(filepath.c_str());
}

std::vector<std::string> Import::convert(const char* filepath) const {
  std::ifstream file(filepath);
  std::vector<std::string> lines;
  std::string line;
  while (std::getline(file, line)) {
    if (!line.empty() && line[line.size() - 1] == '\r') {
      line = line.substr(0, line.size() - 1);
    }
    if (!line.empty() && line.size() > 1) {
      lines.push_back(line);
    }
  }
  file.close();
  return lines;
}
