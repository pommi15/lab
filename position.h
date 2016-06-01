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
#include "direction.h"

struct position {
  int x;
  int y;
  std::string to_string() const {
    std::string str = "x";
    str += this->x;
    str += "y";
    str += this->y;
    return str;
  }
  bool operator==(const position& rhs) const {
    return (x == rhs.x && y == rhs.y);
  }
  bool operator!=(const position& rhs) const {
    return (x != rhs.x || y != rhs.y);
  }
  bool operator<(const position& rhs) const {
    return ((x < rhs.x) || (y < rhs.y));
  }
  bool operator>(const position& rhs) const { return (x > rhs.x || y > rhs.y); }
  bool operator<=(const position& rhs) const {
    return (x <= rhs.x || y <= rhs.y);
  }
  bool operator>=(const position& rhs) const {
    return (x >= rhs.x || y >= rhs.y);
  }
};
