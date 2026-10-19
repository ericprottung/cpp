#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
class BitcoinExchange {
    private:
        std::map<std::string, double> data; 
        bool validateDate(const std::string &line);
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        ~BitcoinExchange();
        void   processInput(const char *fileName);
}   ;

#endif
