#include "ScalarConverter.hpp"
#include <exception>
#include <iostream>
#include <cstdio>

int main(int ac, char *argv[]) {
    if (ac != 2) {
        std::cerr << "wrong amount of arguments!\n";
        return 1;
    }
    try {
        ScalarConverter::convert(argv[1]);
    }
    catch (std::exception &e) {
        std::cout << e.what();
    }
    return 0;
}