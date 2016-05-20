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

#include "direction.h"

struct position {
  int x;
  int y;
  bool operator==(const position& a) const
  {
      return (x == a.x && y == a.y);
  }
  bool operator!=(const position& a) const
  {
      return (x != a.x || y != a.y);
  }
  bool operator<(const position& a) const
  {
      return (x < a.x || y < a.y);
  }
  bool operator>(const position& a) const
  {
      return (x > a.x || y > a.y);
  }
  bool operator<=(const position& a) const
  {
      return (x <= a.x || y <= a.y);
  }
  bool operator>=(const position& a) const
  {
      return (x >= a.x || y >= a.y);
  }
};
