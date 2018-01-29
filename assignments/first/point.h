#ifndef POINT
#define POINT

#include "object.h"
#include <vector>
#include <iomanip>

using namespace std;
using namespace acp;

class Point : public Object<PV2> {
};

typedef vector<PTR<Point>> Points;

Primitive2(XOrder, Point*, a, Point*, b);

Primitive2(YOrder, Point*, a, Point*, b);

Primitive2(CCW, Point*, a, Point*, b);

Primitive3(LeftTurn, Point*, a, Point*, b, Point*, c);

class InputPoint : public Point {
 public:
  InputPoint (double x, double y) { set(PV2::input(x, y)); }
};

class Vector : public Point {
  PV2 calculate () { return h->get() - t->get(); }
 protected:
  PTR<Point> t, h;
 public:
  Vector (Point *t, Point *h) : t(t), h(h) {}
};

class Normal : public Point {
  PV2 calculate () { 
    PV2 q = h->get() - t->get();
    return PV2(- q.y, q.x); 
  }
 protected:
  PTR<Point> t, h;
 public:
  Normal (Point *t, Point *h) : t(t), h(h) {}
};

class LineIntersection : public Point {
  PV2 calculate () {
    PV2 ap = a->get(), cp = c->get(), u = b->get() - ap, v = d->get() - cp;
    Parameter k = (cp - ap).cross(v)/u.cross(v);
    return ap + k*u;
  }
 protected:
  PTR<Point> a, b, c, d;
 public:
  LineIntersection (Point *a, Point *b, Point *c, Point *d) : a(a), b(b), c(c), d(d) {}
};

void pp (Point *p);

#endif
