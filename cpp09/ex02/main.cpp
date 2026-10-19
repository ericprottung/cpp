#include <ctime>
#include <iomanip>
#include <stdexcept>
#include <iostream>
#include "PmergeMe.hpp"
#include <ctime>

int main (int ac, char *av[]) {
    if (ac != 1) {
        std::cerr << "\033[31m" << "Error: Wrong number of arguments provided\n"
        << "\033[0m" << " └── Expected input: ./btc [Input file]\n";
        return 1;
    }
    (void)av;
    std::vector<int > test;
    // test.push_back(35);
    // test.push_back(51);
    // test.push_back(63);
    // test.push_back(3);
    // test.push_back(29);
    // test.push_back(56);
    // test.push_back(42);
    // test.push_back(17);
    // test.push_back(8);
    // test.push_back(12);
    // test.push_back(44);
    // test.push_back(21);
    test.push_back(67);
    test.push_back(6);
    test.push_back(38);
    test.push_back(54);
    test.push_back(15);
    test.push_back(48);
    test.push_back(27);
    test.push_back(60);
    test.push_back(1);
    test.push_back(33);
    test.push_back(46);
    // test.push_back(19);
    // test.push_back(58);
    test.push_back(10);
    test.push_back(40);
    test.push_back(25);
    test.push_back(65);
    test.push_back(4);
    test.push_back(36);
    test.push_back(52);
    test.push_back(14);
    test.push_back(49);
    test.push_back(22);
    // test.push_back(61);
    // test.push_back(7);
    // test.push_back(31);
    // test.push_back(55);
    // test.push_back(18);
    // test.push_back(43);
    // test.push_back(26);
    // test.push_back(64);
    // test.push_back(9);
    // test.push_back(37);
    // test.push_back(50);
    // test.push_back(2);
    // test.push_back(34);
    // test.push_back(47);
    // test.push_back(20);
    // test.push_back(59);
    // test.push_back(11);
    // test.push_back(41);
    // test.push_back(28);
    // test.push_back(66);
    // test.push_back(5);
    // test.push_back(39);
    // test.push_back(53);
    // test.push_back(16);
    // test.push_back(45);
    // test.push_back(23);
    // test.push_back(62);
    // test.push_back(13);
    // test.push_back(32);
    test.push_back(57);
    // test.push_back(24);
    // test.push_back(30);
    
    try {
        PmergeMe sorter(test);
        clock_t time = clock();
        sorter.recursionLoop(1);
        clock_t finish = clock();  
        sorter.printArr();
        std::cout << std::fixed << std::setprecision(3);
        std::cout << "\n" << (finish - time) / (double)(CLOCKS_PER_SEC) * 1000 << " ms";
        std::cout << std::endl;
    } catch (std::exception &e) {
        std::cerr << "\033[31m" << "Error: An error occurred while running the program\n"
        << "\033[0m" << " └── " << e.what() << "\n";
    }
}