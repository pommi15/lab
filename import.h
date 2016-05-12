#ifndef IMPORT_H_
#define IMPORT_H_
#include <string>
#include <iostream>
#include <vector>
#include <iostream>
#include <fstream>

class Import {
 public:
  Import();  // constructor
  std::vector<std::string> input_vector;  // vector for the read in numbers
  void read(std::string filepath);  // function to read the numbers into the
};
#endif  // TXTIMPORT_H_
