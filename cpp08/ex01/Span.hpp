#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <iterator>
#include <stdexcept>

class Span {
    public:
        Span();
        Span(unsigned int N);
        Span(const Span &other);
        Span &operator=(const Span &other);
        ~Span();

        void            addNumber(int number);
        template<typename It>
        void            addNumbers(It begin, It end) {
            if (static_cast<unsigned long>(std::distance(begin, end)) > length - vec.size())
                throw std::runtime_error("Input too big!");
            vec.insert(vec.end(), begin, end);
        }
        unsigned int    shortestSpan() const;
        unsigned int    longestSpan() const;

    private:
        std::vector<int>    vec;
        unsigned int        length;
};

#endif
