#include "Array.hpp"
#include <exception>
#include <iostream>
#include <string>

int main() {
    
    Array<int> intArray(5);
    
    for(std::size_t i = 0; i < 5; i++)
        intArray[i] = i;
    
    for(std::size_t i = 0; i < 5; i++)
        std::cout << intArray[i] << '\n';
    
    try {
        intArray[16] = 7;
    } catch (std::exception &e) {
        std::cout << e.what() << "\n";
    }
    
    Array<std::string> strArray(5);
    
    std::string app = "hi";
    for(std::size_t i = 0; i < 5; i++) {
        strArray[i] = app;
        app.append("hi");
    }
    
    for(std::size_t i = 0; i < 5; i++)
        std::cout << strArray[i] << '\n';
    
    try {
        strArray[16] = 7;
    } catch (std::exception &e) {
        std::cout << e.what() << "\n";
    }
    
    
    return 0;
}