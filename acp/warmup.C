#include "point.h"

bool intersects (Point *t1, Point *h1, Point *t2, Point *h2)
{
  return LeftTurn(t1, t2, h2) == - LeftTurn(h1, t2, h2) &&
    LeftTurn(t2, t1, h1) == - LeftTurn(h2, t1, h1);
}

main ()
{
  double ax, ay, bx, by, cx, cy, dx, dy;
  cerr << "Input format: tail-x tail-y head-x head-y" << endl;
  cerr << "enter first segment: ";
  cin >> ax >> ay >> bx >> by;
  cerr << "enter second segment: ";
  cin >> cx >> cy >> dx >> dy;
  PTR<Point> a = new InputPoint(ax, ay), b = new InputPoint(bx, by),
    c = new InputPoint(cx, cy), d = new InputPoint(dx, dy);
  if (intersects(a, b, c, d)) {
    PTR<Point> p = new LineIntersection(a, b, c, d);
    PV2 pp = p->getApprox();
    cerr << "Intersection point is (" << pp.x.mid() << " " << pp.y.mid() << ")" << endl;
  }
  else
    cerr << "No intersection." << endl;
}
