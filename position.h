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
