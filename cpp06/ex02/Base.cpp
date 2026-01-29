#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <exception>
#include <iostream>
#include <unistd.h>

Base::~Base() {}

Base *generate(void)    {
    int number;
    while ((number = rand()) > RAND_MAX - (RAND_MAX - 2) % 3) {}; 
    switch (number % 3) {
        case 0 :
        {
            A *a = new A();
            return dynamic_cast<Base *>(a);
        }
        case 1 :
        {
            B *b = new B();
            return dynamic_cast<Base *>(b);
        }
        case 2 :
        {
            C *c = new C();
            return dynamic_cast<Base *>(c);
        }
    }
    return NULL;
}

void identify(Base* p) {
    A *a = dynamic_cast<A*>(p);
    if (a != NULL) {
        std::cout << "A\n";
        return ;
    }
    B *b = dynamic_cast<B *>(p);
    if (b != NULL) {
        std::cout << "B\n";
        return ;
    }
    C *c = dynamic_cast<C*>(p);
    if (c != NULL) {
        std::cout << "C\n";
        return ;
    }
}

void test() {
        throw std::exception();
}

void identify(Base& p) {
    try {
        A a = dynamic_cast<A&>(p);
        std::cout << "A\n";
    } catch (std::exception &e) {
    }
    try {
        B b = dynamic_cast<B&>(p);
        std::cout << "B\n";
    } catch (std::exception &e) {
    }
    try {
        C c = dynamic_cast<C&>(p);
        std::cout << "C\n";
    } catch (std::exception &e) {
    }
    
}