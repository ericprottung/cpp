#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <unistd.h>
#include <time.h>
#include <iostream>

int main() {
    srand((unsigned)time(NULL));
    Base *randomDerived = generate(); 
    std::cout << "random: ";
    identify(randomDerived);
    A a;
    std::cout << "pointer: ";
    identify(&a);
    Base *b = new B();
    std::cout << "pointer: ";
    identify(b);
    C c;
    std::cout << "pointer: ";
    identify(&c);
    std::cout << "reference: ";
    identify(a);
    std::cout << "reference: ";
    identify(b);
    std::cout << "reference: ";
    identify(c);
}