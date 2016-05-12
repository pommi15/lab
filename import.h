#ifndef TXTIMPORT_H_
#define TXTIMPORT_H_
#include <string>
#include <iostream>
#include <vector>
#include <iostream>
#include <fstream>

class TxtImport {
 public:
  TxtImport();  // constructor
  std::vector<int> input_vector;  // vector for the read in numbers
  void read(std::string filepath);  // function to read the numbers into the
};
#endif  // TXTIMPORT_H_
