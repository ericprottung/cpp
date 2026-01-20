#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point {
    public :
        Point();
        Point(float y, float x);
        Point(Point& other);
        Point& operator=(const Point& other);
        ~Point();
        const Fixed& getY() const;
        const Fixed& getX() const;
    private:
        Fixed const y;
        Fixed const x;
}   ;

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif