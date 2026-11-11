#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <list>

int main()
{
    std::cout << "=== Subject test ===" << std::endl;
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    std::cout << "=== 10000 random numbers via addNumbers ===" << std::endl;
    std::vector<int> fill;
    srand(time(NULL));
    for (unsigned int i = 0; i < 10000; i++)
        fill.push_back(rand() % 1000000);
    Span new_sp = Span(fill.size());
    new_sp.addNumbers(fill.begin(), fill.end());
    std::cout << new_sp.shortestSpan() << std::endl;
    std::cout << new_sp.longestSpan() << std::endl;

    std::cout << "=== addNumbers with std::list ===" << std::endl;
    std::list<int> lst;
    lst.push_back(100);
    lst.push_back(-50);
    lst.push_back(20);
    Span lsp(3);
    lsp.addNumbers(lst.begin(), lst.end());
    std::cout << lsp.shortestSpan() << " " << lsp.longestSpan() << std::endl;

    std::cout << "=== INT_MIN / INT_MAX ===" << std::endl;
    Span ext(2);
    ext.addNumber(INT_MIN);
    ext.addNumber(INT_MAX);
    std::cout << ext.shortestSpan() << " " << ext.longestSpan() << std::endl;

    std::cout << "=== Error cases ===" << std::endl;
    try {
        sp.addNumber(42);
    } catch (std::exception &e) {
        std::cout << "addNumber on full span: " << e.what() << std::endl;
    }
    try {
        Span small(2);
        small.addNumbers(fill.begin(), fill.end());
    } catch (std::exception &e) {
        std::cout << "addNumbers too many: " << e.what() << std::endl;
    }
    try {
        Span one(5);
        one.addNumber(1);
        one.shortestSpan();
    } catch (std::exception &e) {
        std::cout << "shortestSpan with 1 number: " << e.what() << std::endl;
    }
    try {
        Span empty;
        empty.longestSpan();
    } catch (std::exception &e) {
        std::cout << "longestSpan on empty: " << e.what() << std::endl;
    }
    return 0;
}
