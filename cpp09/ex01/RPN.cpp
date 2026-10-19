#include "RPN.hpp"
#include <cctype>
#include <iostream>
#include <sstream>
#include <stdexcept>

const std::string RPN::operators = "+-/*";

RPN::RPN() {}
RPN::RPN(const RPN& other) {(void)other;}
RPN& RPN::operator=(const RPN& other) {(void)other; return *this;}
RPN::~RPN() {}

void RPN::operation(int opSpecifier) {
    int tmp;
    
    tmp = numberStack.top();
    numberStack.pop();
    switch (opSpecifier) {
        case 0:
        numberStack.top() = numberStack.top() + tmp;
        break;
        case 1:
        numberStack.top() = numberStack.top() - tmp;
        break;
        case 2:
        if (tmp == 0)
            throw std::runtime_error("division by 0 detected");
        numberStack.top() = numberStack.top() / tmp;
        break;
        case 3:
        numberStack.top() = numberStack.top() * tmp;
    }
}

void RPN::solver(const std::string &token) {
    if (numberStack.size() < 2)
        throw std::runtime_error(token + " => operator provided without enough numbers");
    operation(operators.find(token));
}

void RPN::loop(const char *input) {
    std::istringstream iss(input);
    std::string token;
    while (iss >> token) {
        if (token.size() != 1)
            throw std::runtime_error(token + " => token is not of size one");
        else if (std::isdigit(token[0]))
            numberStack.push(token[0] - 48);
        else if (operators.find(token) != std::string::npos)
            solver(token);
        else
            throw std::runtime_error(token + " => invalid token provided");
    }
    if (numberStack.size() > 1)
        throw std::runtime_error("expression lacks at least one operator");
    std::cout << numberStack.top() << "\n";
}