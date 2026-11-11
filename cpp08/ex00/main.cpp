#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

int main() {
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(5);
    vec.push_back(46);
    vec.push_back(5);

    std::cout << "=== vector: find 46 ===" << std::endl;
    try {
        std::vector<int>::iterator it = easyfind(vec, 46);
        std::cout << "found " << *it << " at index " << (it - vec.begin()) << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "=== vector: find 5 (first occurrence) ===" << std::endl;
    try {
        std::vector<int>::iterator it = easyfind(vec, 5);
        std::cout << "found " << *it << " at index " << (it - vec.begin()) << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "=== vector: find 42 (missing) ===" << std::endl;
    try {
        easyfind(vec, 42);
        std::cout << "should not be printed" << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::list<int> lst;
    lst.push_back(-1);
    lst.push_back(0);
    lst.push_back(1);
    std::cout << "=== list: find 0 / find 7 ===" << std::endl;
    try {
        std::cout << "found " << *easyfind(lst, 0) << std::endl;
        easyfind(lst, 7);
        std::cout << "should not be printed" << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::deque<int> empty;
    std::cout << "=== empty deque: find 1 ===" << std::endl;
    try {
        easyfind(empty, 1);
        std::cout << "should not be printed" << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
