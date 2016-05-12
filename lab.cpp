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
 #include "labyrinth.h"


int main(int argc, char* argv[]) {
  auto import = std::make_shared<Import>(argv[1]);
  for (auto i : import->input_vector) {
    std::cout << i << std::endl;
  }
  std::cout << "BREAK" << std::endl;
  auto laby = std::make_shared<Labyrinth>(import->input_vector);
  for (auto i : laby->maze){
    for (auto j : i){
      if(j){
        std::cout << "#";
      }else{
        std::cout << " ";
      }

    }
    std::cout << std::endl;
  }
  return 0;
}
