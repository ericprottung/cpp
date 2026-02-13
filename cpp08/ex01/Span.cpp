#include "Span.hpp"
#include <algorithm>
#include <climits>
#include <cstdlib>
#include <iterator>
#include <stdexcept>
#include <vector>

Span::Span() {
    length = 0;
}

Span::Span(unsigned int N) {
    length = N;
}

Span::Span(const Span &other) {
    *this = other;
}

Span& Span::operator=(const Span &other) {
    vec = other.vec;
    length = other.length;
    return *this;
}

Span::~Span() {}

void    Span::addNumber(int number) {
    if (vec.size() >= length)
        throw std::runtime_error("Already full!");
    vec.push_back(number);
}

void    Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    if (vec.size() + (end - begin) > length)
        throw std::runtime_error("Input too big!");
    vec.insert(vec.end(), begin, end);
}

unsigned int     Span::shortestSpan() {
    if (vec.size() < 2)
        throw std::runtime_error("Not enough content to calculate span!");
    
    std::vector<int> sort_vec = vec;
    std::sort(sort_vec.begin(), sort_vec.end());
    long span = std::labs((long)sort_vec.at(1) - (long)sort_vec.at(0));
    for (unsigned int i =2; i < sort_vec.size(); i++) {
        if  (std::labs((long)sort_vec.at(i) - (long)sort_vec.at(i - 1)) < span)
            span = std::labs((long)sort_vec.at(i) - (long)sort_vec.at(i - 1));
    } 
    return span;
}

unsigned int     Span::longestSpan() {
    if (vec.size() < 2)
        throw std::runtime_error("Not enough content to calculate span!");
   int min = *std::min_element(vec.begin(), vec.end());
   int max = *std::max_element(vec.begin(), vec.end());
   return std::labs((long)max - (long)min);
}