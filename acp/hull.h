#ifndef HULL
#define HULL

#include "point.h"

class CCWOrder {
  Point *o;
 public:
  CCWOrder (Point *o) : o(o) {}
  bool operator() (Point *a, Point *b) const {
    return LeftTurn(a, o, b) == -1;
  }
};

void convexHull (Points &points, Points &hull);

#endif
