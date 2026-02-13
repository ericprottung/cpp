#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include <stdexcept>

template<typename T>

typename T::iterator easyfind(T &container, int find) {
    typename T::iterator i = std::find(container.begin(), container.end(), find);
    if (i != container.end())
        return i;
    throw std::runtime_error("Integer not found!");
}

#endif
