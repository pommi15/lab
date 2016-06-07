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
/** call convert with c_str */
std::vector<std::string> Import::convert(const std::string& filepath) const {
  return this->convert(filepath.c_str());
}
/** convert file to vector of strings */
std::vector<std::string> Import::convert(const char* filepath) const {
  /** open file */
  std::ifstream file(filepath);
  /** vector with lines */
  std::vector<std::string> lines;
  /** current line */
  std::string line;
  /** go through each line */
  while (std::getline(file, line)) {
    /** check if line is not empty and has a windows line ending */
    if (!line.empty() && line[line.size() - 1] == '\r') {
      /** remove the windows line ending */
      line = line.substr(0, line.size() - 1);
    }
    /** check if line is not empty and the size is bigger than one */
    if (!line.empty() && line.size() > 1) {
      lines.push_back(line);
    }
  }
  /** close the file */
  file.close();
  return lines;
}
