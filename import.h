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
#include <fstream>

class Import {
 public:
  Import(std::string filepath);  // constructor
  std::vector<std::string> input_vector;  // vector for the read in numbers
  std::string filepath;
};

