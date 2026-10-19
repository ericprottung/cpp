#include "BitcoinExchange.hpp"
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>

bool BitcoinExchange::validateDate(const std::string &line) {
    int year;
    int month;
    int day;
    if (sscanf(line.c_str(), "%d-%d-%d", &year, &month, &day) != 3 || line.length() != 10)
        return false;
    tm stamp = {};
    stamp.tm_year = year - 1900;
    stamp.tm_mon = month - 1;
    stamp.tm_mday = day;
    if (mktime(&stamp) == -1 || stamp.tm_year != year - 1900 || stamp.tm_mon != month - 1 || stamp.tm_mday != day)    
       return false;
    return true;
}

void BitcoinExchange::processInput(const char* fileName) {
    std::ifstream file(fileName);
    
    if (!file.is_open())
        throw std::runtime_error("Input file couldn't be opened"); 
    
    std::string line;
    unsigned long splitPos;
    
    std::getline(file, line);
    if (line.compare("date | value"))
        throw std::runtime_error("Head of Input file wrong"); 
    
    while (std::getline(file, line)) {
        splitPos = line.find('|');
        if (splitPos == std::string::npos || splitPos != line.find_last_of('|')) {
            std::cout << "Line format wrong\n"; 
            continue ; 
        }
        std::string key = line.substr(0, line.find(" "));
        std::map<std::string, double>::iterator it = data.lower_bound(key);
        if (it == data.end()) {
            std::cout << key << " => key not found\n"; 
            continue ; 
        }
        std::string value = line.substr(splitPos + 1);
        char* pEnd;
        double number = strtod(value.c_str() + value.find_first_not_of(" "), &pEnd);
        if (*pEnd != 0 || value.c_str() + value.find_first_not_of(" ") == pEnd || number > (double)1000 || number < 0) {
            std::cout << value.c_str() + value.find_first_not_of(" ") << " => value not usable\n"; 
            continue ; 
        }
        
        std::cout << (*it).first << " => " << number << " = " << number * (*it).second << "\n";
    }
}

BitcoinExchange::BitcoinExchange() {
    std::ifstream file("data.csv");
    if (!file.is_open())
        throw std::runtime_error("data.csv not found or not accessible"); 
    
    std::string line;
    unsigned long splitPos;
    char* pEnd;
    
    std::getline(file, line);
    if (line.compare("date,exchange_rate"))
        throw std::runtime_error("Head of data.csv file wrong"); 
    
    while (std::getline(file, line)) {
        splitPos = line.find(',');
        if (splitPos == std::string::npos || splitPos != line.find_last_of(','))
            throw std::runtime_error(line + " => this line is parsed incorrectly"); 
        
        std::string value = line.substr(splitPos + 1);
        std::string date = line.substr(0, splitPos);
        if (!validateDate(date))
            throw std::runtime_error(line + " => date format incorrect"); 
        
        std::pair<std::string, double> entry;
        entry.first = date;
        entry.second = strtod(value.c_str(), &pEnd);
        data.insert(entry); 
    }
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {(void)other;}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {(void)other; return *this;}
BitcoinExchange::~BitcoinExchange() {}


