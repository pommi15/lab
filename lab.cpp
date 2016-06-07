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
#include <string>
#include <iostream>
#include <fstream>
#include <getopt.h>
#include "solver.h"

#define no_argument 0
#define required_argument 1
#define optional_argument 2

/** usage string */
static const char USAGE[] =
    R"(lab
  Read in a maze from a file and let one or
  more bots find the exit.
  Usage:
    lab <FILE>
    lab (-g | --graphic) <FILE>
    lab (-h | --help)
    lab (-v | --version)

  Options:
    -h --help       Show this help message
    -g --graphic    Visualise the way of the bots
    -v --version    Show the version
)";

/** version string */
static const char VERSION[] = "lab - maze solver: version 1.0";

int main(int argc, char* argv[]) {
  /** check if enough arguments where provided */
  if (argc < 2) {
    std::cerr << "Error " << argv[0] << ": "
              << "Not enough arguments provided." << std::endl;
    return EXIT_FAILURE;
  }

  /** options for getopt_long */
  const struct option longopts[] = {
      {"version", no_argument, 0, 'v'},
      {"help", no_argument, 0, 'h'},
      {"graphic", no_argument, 0, 'g'},
      {0, 0, 0, 0},
  };
  int index;
  int iarg = 0;
  bool graphic = false;

  opterr = 1;
  /** get all option parameters */
  while (iarg != -1) {
    iarg = getopt_long(argc, argv, "vhg", longopts, &index);
    switch (iarg) {
      case 'h':
        /** help - print the usage and exit */
        std::cout << USAGE << std::endl;
        return EXIT_SUCCESS;
        break;

      case 'v':
        /** version - print the version and exit */
        std::cout << VERSION << std::endl;
        return EXIT_SUCCESS;
        break;

      case 'g':
        /** graphical output flag */
        graphic = true;
        break;
    }
  }
  /** try to open the filepath */
  std::ifstream file(argv[argc - 1]);
  /** check if file could be opened */
  if (!file.good()) {
    std::cerr << "Error " << argv[0] << ": "
              << "Can't open filepath." << std::endl;
    file.close();
    return EXIT_FAILURE;
  }
  /** close the file */
  file.close();
  /** ptr to solver object with path to maze and graphic option */
  auto solver = std::make_shared<Solver>(std::string(argv[argc - 1]), graphic);
  solver->print_maze();
  solver->solve();
  solver->print_result();
  return 0;
}
