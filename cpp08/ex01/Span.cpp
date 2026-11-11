#include "Span.hpp"
#include <algorithm>
#include <cstdlib>
#include <stdexcept>
#include <vector>

Span::Span() : length(0) {}

Span::Span(unsigned int N) : length(N) {}

Span::Span(const Span &other) : vec(other.vec), length(other.length) {}

Span& Span::operator=(const Span &other) {
    if (this != &other) {
        vec = other.vec;
        length = other.length;
    }
    return *this;
}

Span::~Span() {}

void    Span::addNumber(int number) {
    if (vec.size() >= length)
        throw std::runtime_error("Already full!");
    vec.push_back(number);
}

unsigned int    Span::shortestSpan() const {
    if (vec.size() < 2)
        throw std::runtime_error("Not enough content to calculate span!");

    std::vector<int> sort_vec = vec;
    std::sort(sort_vec.begin(), sort_vec.end());
    long span = (long)sort_vec[1] - (long)sort_vec[0];
    for (size_t i = 2; i < sort_vec.size(); i++) {
        long diff = (long)sort_vec[i] - (long)sort_vec[i - 1];
        if (diff < span)
            span = diff;
    }
    return static_cast<unsigned int>(span);
}

unsigned int    Span::longestSpan() const {
    if (vec.size() < 2)
        throw std::runtime_error("Not enough content to calculate span!");
    int min = *std::min_element(vec.begin(), vec.end());
    int max = *std::max_element(vec.begin(), vec.end());
    return static_cast<unsigned int>((long)max - (long)min);
}
