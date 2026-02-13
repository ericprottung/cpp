#include "Span.hpp"
#include <iostream>
#include <cstdlib>

int main()
{
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    std::vector<int> fill;
    srand(time(NULL));
    for (unsigned int i = 0; i < 10000; i++)
        fill.push_back(rand() % 1000000);
    Span new_sp = Span(fill.size());
    new_sp.addNumbers(fill.begin(), fill.end());
    std::cout << new_sp.shortestSpan() << std::endl;
    std::cout << new_sp.longestSpan() << std::endl;
    return 0;
}