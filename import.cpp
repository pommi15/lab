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
Import::Import(std::string filepath) {
  this->filepath = filepath;
  std::ifstream input(this->filepath.c_str());  // open the file
  std::string line;                             // temp variable
  while (getline(input, line)) {           // read lines as long as the file is
    if(!line.empty()){
      this->input_vector.push_back(line);    // save the line to the vector
    }
  }
}
