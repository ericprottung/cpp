#include "ScalarConverter.hpp"
#include <cctype>
#include <cerrno>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <ios>
#include <string.h>
#include <iostream>

static bool hasDigit(const std::string& str) {
    return str.find_first_of("0123456789") != std::string::npos;
}

static void printSpecialCase(const std::string& literal)
{
    std::cout << "char: impossible\n"
              << "int: impossible\n";

    if (literal == "nan" || literal == "nanf")
        std::cout << "float: nanf\ndouble: nan\n";
    else if (literal == "-inf" || literal == "-inff")
        std::cout << "float: -inff\ndouble: -inf\n";
    else if (literal == "+inf" || literal == "+inff")
        std::cout << "float: +inff\ndouble: +inf\n";
}

static void printImpossible(const std::string& literal) {
    (void)literal;
    std::cout << "char: impossible\n"
    << "int: impossible\n"
    << "float: impossible\n"
    << "double: impossible\n";
}

static void printChar(const std::string& literal) {
    char c;
    if (literal.size() == 3 && literal[0] == '\'' && literal[2] == '\'')
        c = literal[1];
    else
        c = literal[0];

    if (!std::isprint(static_cast<unsigned char>(c)))
        std::cout << "char: non printable\n";
    else
        std::cout << "char: '" << c << "'\n";
    
    std::cout << "int: " << static_cast<int>(c) << "\n";
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(c) << "f\n";
    std::cout << "double: " << static_cast<double>(c) << "\n";
}

static void printInt(const std::string& literal) {
    bool overflow = false;
    double d = std::strtod(literal.c_str(), NULL);
    int i = static_cast<int>(d);
    if (d < CHAR_MIN || d > CHAR_MAX)
        std::cout << "char: impossible\n";
    else if (!std::isprint(static_cast<unsigned char>(i)))
        std::cout << "char: non printable\n";
    else
        std::cout << "char: '" << static_cast<unsigned char>(i) << "'\n";
    if (d < INT_MIN || d > INT_MAX) {
        std::cout << "int: impossible\n";
        overflow = true;
    }
    else
        std::cout << "int: " << i << "\n";
    if (overflow)
        std::cout << "float: impossible\ndouble: impossible\n";
    else {
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << static_cast<float>(i) << "f\n";
        std::cout << "double: " << static_cast<double>(i) << "\n"; 
    }
}

static void printFloat(const std::string& literal) {
    float f = static_cast<float>(std::strtod(literal.c_str(), NULL));
    double d = static_cast<double>(f);
    if (d < CHAR_MIN || d > CHAR_MAX)
        std::cout << "char: impossible\n";
    else if (!std::isprint(static_cast<unsigned char>(f)))
        std::cout << "char: non printable\n";
    else
        std::cout << "char: '" << static_cast<char>(f) << "'\n";
    if (d < INT_MIN || d > INT_MAX)
        std::cout << "int: impossible\n";
    else
        std::cout << "int: " << static_cast<int>(f) << "\n";
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << f << "f\n";
    std::cout << "double: " << static_cast<double>(f) << "\n";  
}

static void printDouble(const std::string& literal) { 
    double d = std::strtod(literal.c_str(), NULL);
    if (d < CHAR_MIN || d > CHAR_MAX)
        std::cout << "char: impossible\n";
    else if (!std::isprint(static_cast<unsigned char>(d)))
        std::cout << "char: non printable\n";
    else
        std::cout << "char: '" << static_cast<char>(d) << "'\n";
    if (d < INT_MIN || d > INT_MAX)
        std::cout << "int: impossible\n";
    else
        std::cout << "int: " << static_cast<int>(d) << "\n";
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(d) << "f\n";
    std::cout << "double: " << d << "\n";
}

#define CHAR 0
#define INT 1
#define FLOAT 2
#define DOUBLE 3
#define SPECIAL 4
#define IMPOSSIBLE 5

static int parseType(const std::string& literal) {
    char *strEnd;
    std::strtod(literal.c_str(), &strEnd);
    if ((literal.size() <= 3 && literal[0] == '\'' && literal[2] == '\'')
        || (literal.size() == 1 && !std::isdigit(literal[0])))
        return CHAR;
    if (literal == "nan" || literal == "nanf"
        ||literal == "-inf" || literal == "-inff"
        || literal == "+inf" || literal ==  "+inff")
        return SPECIAL;
     size_t dotPos = literal.find('.');
    if (dotPos != std::string::npos && dotPos != 0 && std::isdigit(literal[dotPos - 1]) && literal.size() > dotPos + 1 && std::isdigit(literal[dotPos + 1])) {
        if (strlen(strEnd) == 1 && strEnd[0] == 'f')
            return FLOAT;
        else if (strlen(strEnd) == 0)
            return DOUBLE;
    }
    else if (dotPos == std::string::npos && hasDigit(literal) && !strlen(strEnd))
        return INT;
    return IMPOSSIBLE;
}

void    ScalarConverter::convert(const std::string &literal) {
    void (*func[])(const std::string&) = {
        &printChar,
        &printInt,
        &printFloat,
        &printDouble,
        &printSpecialCase,
        &printImpossible
    };
    int type = parseType(literal);
    func[type](literal);
}