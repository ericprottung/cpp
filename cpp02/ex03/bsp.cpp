#include "Fixed.hpp"
#include "Point.hpp"

static Fixed calcTriangle(const Point& p1, const Point& p2, const Point& p3) {
    Fixed result = Fixed(0.5f) * ((p1.getX() * (p2.getY() - p3.getY())) + (p2.getX() * (p3.getY() - p1.getY())) + (p3.getX() * (p1.getY() - p2.getY())));
    if (result < 0)
        result = result * Fixed(-1);
    return result;
}

bool bsp( Point const a, Point const b, Point const c, Point const point) {
    Fixed area = calcTriangle(a, b, c);
    Fixed a1 = calcTriangle(a, b, point);
    Fixed a2 = calcTriangle(b, c, point);
    Fixed a3 = calcTriangle(c, a, point);
    if (a1 == 0 || a2 == 0 || a3 == 0)
        return false;
    return area == a1 + a2 + a3;
}