#include <stdexcept>
#include <iostream>
#include "RPN.hpp"

int main (int ac, char *av[]) {
    if (ac != 2) {
        std::cerr << "\033[31m" << "Error: Wrong number of arguments provided\n"
        << "\033[0m" << " └── Expected input: ./btc [Input file]\n";
        return 1;
    }
    try {
        RPN rpn_calc;
        rpn_calc.loop(av[1]);
    } catch (std::exception &e) {
        std::cerr << "\033[31m" << "Error: An error occurred while running the program\n"
        << "\033[0m" << " └── " << e.what() << "\n";
    }
}