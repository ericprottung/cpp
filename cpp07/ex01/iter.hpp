#ifndef ITER_HPP
# define ITER_HPP

#include <cstddef>
template<typename T, typename U>

void    iter(T* arr, const size_t length, U applyFunction) {
    for (size_t i = 0; i < length; i++) {
       applyFunction(arr[i]); 
    }
}

#endif