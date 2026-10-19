#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>
#include <vector>

template<typename T>
class MutantStack : public std::stack<T> {
    public:
        typedef T* iterator ;
        iterator begin() {
            return &this->top() - this->size();
        }
        iterator end() {
            return &this->top() + 1;
        }
}   ;

#endif 