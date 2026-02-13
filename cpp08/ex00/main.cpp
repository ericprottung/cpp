# include <iostream>
#include "easyfind.hpp"
#include <vector>

int main() {
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(5);
    vec.push_back(46);
    vec.push_back(5);
    try {
        std::vector<int>::iterator it = easyfind(vec, 46); 
        std::cout << *it << "\n";
    } catch (std::exception &e) {
        std::cout << e.what();
    }
    return 0;
}