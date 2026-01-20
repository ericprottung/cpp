#include "Point.hpp"
#include "Fixed.hpp"
#include <iostream>

Point::Point() : y(0) , x(0) {
    std::cout << "Default constructor of class Point has been called!\n";
}

Point::Point(float y, float x) : y(y) , x(x) {
    std::cout << "Initializing constructor of class Point has been called!\n"; 
}

Point::Point(Point& other) : y(other.y) , x(other.x){
    std::cout << "Copy constructor of class Point has been called!\n";
}

Point& Point::operator=(const Point& other) {
    std::cout << "Copy assignment constructor of class Point has been called!\n";
    (void)other;
    return *this;
}

Point::~Point() {
    std::cout << "Deconstructor of class Point has been called!\n";
}

const Fixed& Point::getY() const {
   return y; 
}

const Fixed& Point::getX() const {
   return x;
}