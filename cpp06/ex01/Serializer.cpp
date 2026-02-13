#include "Serializer.hpp"
#include "Data.hpp"
#include <stdint.h>

uintptr_t Serializer::serialize(Data* ptr) {   
    uintptr_t value = reinterpret_cast<uintptr_t>(ptr);
    return value;
}

Data* Serializer::deserialize(uintptr_t raw){
    Data *ptr = reinterpret_cast<Data*>(raw);
    return ptr;
}

Serializer::Serializer(){}

Serializer::Serializer(const Serializer &other){
    (void)other;
}

Serializer& Serializer::operator=(const Serializer &other){
    (void)other;
    return *this;
}

Serializer::~Serializer() {}