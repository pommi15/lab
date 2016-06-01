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
#include "solver.h"

int main(int argc, char* argv[]) {
  auto solver = std::make_shared<Solver>(std::string(argv[1]));
  solver->solve();
  return 0;
}
