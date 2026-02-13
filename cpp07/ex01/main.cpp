#include "iter.hpp"
#include <cctype>
#include <iostream>

void addOne(int i) {
    i +=1;
}

void printInt(int i) {
    std::cout << i << "\n";
}

void printStr(std::string &i) {
    std::cout << i << "\n";
}

void changeStr(std::string &i) {
    if (i.length() > 0)
        i.at(0) = ' ';
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    ::iter(arr, 8, addOne);
    ::iter(arr, 8, printInt);
    
    std::string strArr[] = {"hi", "who", "are", "you", "?"};
    ::iter(strArr, 5, changeStr);
    ::iter(strArr, 5, printStr);
    
    return 0;
}