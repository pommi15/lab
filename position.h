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
enum direction
{
  NORTH,
  EAST,
  SOUTH,
  WEST
};

struct position {
  int x;
  int y;
  direction facing;
};
