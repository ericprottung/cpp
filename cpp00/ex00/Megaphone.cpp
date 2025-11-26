#include <iostream>
#include <iomanip>
#include <string>

int main(int ac, char **argv) {
    if (ac == 1) {
        std::cout << "*LOUD AND UNBEARABLE FEEDBACK NOISE*" << std::endl;
        return (1);
    }
    for (int i = 1; i < ac; i++)
    {
        std::string str = argv[i];
        for (size_t j = 0; j < str.size(); j++)
        {
            str[j] = std::toupper(str[j]);
        }
        std::cout << str;

    }
    std::cout << std::endl;
    return (0);
}
