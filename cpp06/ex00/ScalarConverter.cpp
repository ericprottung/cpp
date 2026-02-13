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

static bool hasDigit(const char *str) {
    return std::string(str).find_first_of("0123456789") != std::string::npos;
}
static void printSpecialCase(const char *literal) {
    std::cout << "char: impossible\n"
    << "int: impossible\n";
    if (!strncmp(literal, "nan", 3))
        std::cout << "float: nanf\ndouble: nan\n";
    if (!strncmp(literal, "-inf", 4))
        std::cout << "float: -inff\ndouble: -inf\n";
    if (!strncmp(literal, "+inf", 4))
        std::cout << "float: +inff\ndouble: +inf\n";
}

static void printImpossible(const char* literal) {
    (void)literal;
    std::cout << "char: impossible\n"
    << "int: impossible\n"
    << "float: impossible\n"
    << "double: impossible\n";
}

static void printChar(const char *literal) {
    char c = literal[0 + (strlen(literal) == 3)];
    if (!std::isprint(c))
        std::cout << "char: non printable\n";
    else
        std::cout << "char: '" << c << "'\n";
    std::cout << "int: " << static_cast<int>(c) << "\n";
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(c) << "f\n";
    std::cout << "double: " << static_cast<double>(c) << "\n";
}

static void printInt(const char *literal) {
    double d = strtod(literal, NULL);
    int i = atoi(literal);
    if (i < CHAR_MIN || i > CHAR_MAX)
        std::cout << "char: impossible\n";
    else if (!std::isprint(i))
        std::cout << "char: non printable\n";
    else
        std::cout << "char: '" << static_cast<char>(i) << "'\n";
    if (d < INT_MIN || d > INT_MAX)
        std::cout << "int: overflowed! values unreliable for float and double\n";
    else
        std::cout << "int: " << i << "\n";
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(i) << "f\n";
    std::cout << "double: " << static_cast<double>(i) << "\n"; 
}

static void printFloat(const char *literal) {
    float f = strtof(literal, NULL);
    if (f < CHAR_MIN || f > CHAR_MAX)
        std::cout << "char: impossible\n";
    else if (!std::isprint(static_cast<char>(f)))
        std::cout << "char: non printable\n";
    else
        std::cout << "char: '" << static_cast<char>(f) << "'\n";
    if (f < INT_MIN || f > INT_MAX)
        std::cout << "int: impossible\n";
    else
        std::cout << "int: " << static_cast<int>(f) << "\n";
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << f << "f\n";
    std::cout << "double: " << static_cast<double>(f) << "\n";  
}

static void printDouble(const char *literal) { 
    double d = strtod(literal, NULL);
    if (d < CHAR_MIN || d > CHAR_MAX)
        std::cout << "char: impossible\n";
    else if (!std::isprint(static_cast<char>(d)))
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

static int parseType(const char *literal) {
    char *strEnd;
    strtod(literal, &strEnd);
    if ((strlen(literal) <= 3 && literal[0] == '\'' && literal[2] == '\'')
        || (strlen(literal) == 1 && !std::isdigit(literal[0])))
        return CHAR;
    if (!strcmp(literal, "nan") || !strcmp(literal, "nanf")
        || !strcmp(literal, "-inf") || !strcmp(literal, "-inff")
        || !strcmp(literal, "+inf") || !strcmp(literal, "+inff"))
        return SPECIAL;
    const char *dotPos = strchr(literal, '.');
    if (dotPos && dotPos != literal && std::isdigit(*(dotPos - 1)) && std::isdigit(*(dotPos + 1))) {
        if (strlen(strEnd) == 1 && strEnd[0] == 'f')
            return FLOAT;
        else if (strlen(strEnd) == 0)
            return DOUBLE;
    }
    else if (!dotPos && hasDigit(literal) && !strlen(strEnd))
        return INT;
    return IMPOSSIBLE;
}

void    ScalarConverter::convert(const char *literal) {
    void (*func[])(const char *) = {
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