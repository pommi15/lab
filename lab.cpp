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
 #include <memory>

 #include "import.h"

 using namespace std;

int main(int argc, char* argv[]) {
  auto import = make_shared<Import>(argv[1]);
  for (auto i : import->input_vector) {
    cout << i << endl;
  }

  return 0;
}
