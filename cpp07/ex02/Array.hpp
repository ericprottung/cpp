#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <cstddef>
#include <exception>

template<class T>

class Array {
    public:
        Array() {
            arr = NULL;
            len = 0;
        }
        Array(unsigned int n) {
            arr = new T[n]();
            len = n;
        }
        Array(const Array &other) {
            arr = NULL;
            *this = other;
        } 
        T &operator[](const unsigned int index) {
            if (index >= len)
                throw std::exception();
           return arr[index]; 
        }
        Array &operator=(const Array &other) {
            if (arr != NULL)
                delete[] arr;
            arr = new T[other.len]();
            for (int i = 0; i < other.len; i++) {
                arr[i] = other.arr[i];
            }
            len = other.len;
            return *this;
        }
        unsigned int size() const {
            return len;
        }
        ~Array() {
            delete[] arr;
        }
    private:
        T* arr;
        unsigned int len;
}   ;

#endif