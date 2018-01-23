#include "point.h"

int XOrder::sign ()
{
  return (b->get().x - a->get().x).sign();
}

int YOrder::sign ()
{
  return (b->get().y - a->get().y).sign();
}

int CCW::sign ()
{
  return a->get().cross(b->get()).sign();
}

int LeftTurn::sign ()
{
  return (c->get() - b->get()).cross(a->get() - b->get()).sign();
}

void pp (Point *p)
{
  PV2 pp = p->getApprox();
  cerr << setprecision(16) << "(" << pp.x.mid() << " " 
       << pp.y.mid() << ")" << endl;
}
