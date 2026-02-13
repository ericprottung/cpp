#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template<typename T>

void swap(T& one, T& two) {
    T tmp = one;
    one = two;
    two = tmp;
}

template<typename T>

const T& min(const T& one, const T& two) {
    return (one < two) ? one : two;
}

template<typename T>

const T& max(const T& one, const T& two) {
    return (one > two) ? one : two;
}

#endif