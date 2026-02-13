#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>
#include <stdint.h>

int main() {
    Data obj;
    std::cout << "address of Data obj: "<< &obj << "\n";
    uintptr_t value = Serializer::serialize(&obj);
    std::cout << "converted value: " << value << "\n";
    Data *ptr = Serializer::deserialize(value);
    std::cout << "address of Data *ptr: " << ptr << "\n"; 
    std::cout << ((ptr == &obj) ? "pointers are equal" : "pointers differ") << "\n";
}