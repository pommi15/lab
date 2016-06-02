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
#include <memory>
#include <iostream>
#include <getopt.h>
#include "solver.h"

#define no_argument 0
#define required_argument 1
#define optional_argument 2

static const char USAGE[] =
    R"(lab
  Read in a maze from a file and let one or
  more bots find the exit.
  Usage:
    lab <FILE>
    lab (-g | --graphic) <FILE>
    lab (-m | --menu) <FILE>
    lab (-h | --help)
    lab (-v | --version)

  Options:
    -h --help       Show this help message
    -g --graphic    Visualise the way of the bots
    -m --menu       Show a menu
    -v --version    Show the version
)";

static const char VERSION[] = "lab - maze solver: version 1.0";

    int main(int argc, char* argv[]) {
  if (argc < 2) {
    std::cerr << "Error " << argv[0] << ": "
              << "Not enough arguments provided." << std::endl;
    std::cerr << USAGE << std::endl;
    return EXIT_FAILURE;
  }

  const struct option longopts[] = {
      {"version", no_argument, 0, 'v'},
      {"help", no_argument, 0, 'h'},
      {"graphic", no_argument, 0, 'g'},
      {"menu", no_argument, 0, 'm'},
      {0, 0, 0, 0},
  };
  int index;
  int iarg = 0;

  // turn off getopt error message
  opterr = 1;

  while (iarg != -1) {
    iarg = getopt_long(argc, argv, "vhgm", longopts, &index);

    switch (iarg) {
      case 'h':
        std::cout << USAGE << std::endl;
        return EXIT_SUCCESS;
        break;

      case 'v':
        std::cout << VERSION << std::endl;
        return EXIT_SUCCESS;
        break;

      case 'g':
        std::cout << "You hit graphic" << std::endl;
        break;

      case 'm':
        std::cout << "You hit menu" << std::endl;
        break;
    }
  }
  std::ifstream file(filepath);
  std::cout << argv[argc - 1] << std::endl;
  // auto solver = std::make_shared<Solver>(std::string(argv[1]));
  // solver->solve();
  return 0;
}
