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
#include "direction.h"
/** position struct */
struct position {
  int x;
  int y;
  /** convert position to string */
  std::string to_string() const {
    std::string str = "x ";
    str += std::to_string(this->x);
    str += " y ";
    str += std::to_string(this->y);
    return str;
  }
  /** overload << operator to print position */
  friend std::ostream& operator<<(std::ostream& out, const position& rhs) {
    return out << rhs.to_string();
  }
  /** overload == operator */
  friend bool operator==(const position& lhs, const position& rhs) {
    return ((lhs.x == rhs.x) && (lhs.y == rhs.y));
  }
  /** overload !== operator */
  friend bool operator!=(const position& lhs, const position& rhs) {
    return !(lhs == rhs);
  }
};
