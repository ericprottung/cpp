#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
class Span {
    public:
        Span();
        Span(unsigned int N);
        Span(const Span&other);
        Span &operator=(const Span&other);
        ~Span();
        void    addNumber(int number);
        void    addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
        unsigned int     shortestSpan();
        unsigned int     longestSpan();
    private :
        std::vector<int> vec;
        unsigned int length;
}   ;

#endif