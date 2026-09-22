#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>
#include <stdint.h>

int main() {
    std::cout << "TEST 1\n\n";
    Data a, b, c;
    std::cout << "Check if serialize > deserialize produces original outcome\n";
    std::cout << (Serializer::deserialize(Serializer::serialize(&a)) == &a) << "\n";
    std::cout << (Serializer::deserialize(Serializer::serialize(&b)) == &b) << "\n";
    std::cout << (Serializer::deserialize(Serializer::serialize(&c)) == &c) << "\n";
    std::cout << "Check if NULL serialize > deserialize produces NULL\n";
    std::cout << (Serializer::deserialize(Serializer::serialize(NULL)) == NULL) << "\n";
    Data obj;
    std::cout << "address of Data obj: "<< &obj << "\n";
    uintptr_t value = Serializer::serialize(&obj);
    std::cout << "converted value: " << value << "\n";
    Data *ptr = Serializer::deserialize(value);
    std::cout << "address of Data *ptr: " << ptr << "\n"; 
    std::cout << ((ptr == &obj) ? "pointers are equal" : "pointers differ") << "\n";
}