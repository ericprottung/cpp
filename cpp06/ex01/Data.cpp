#include "Data.hpp"

Data::Data() : something(1) {}

Data::Data(const Data &other) : something(other.something) {}

Data& Data::operator=(const Data &other){
    something = other.something;
    return *this;
}

Data::~Data() {}