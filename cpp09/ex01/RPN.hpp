#ifndef RPN_HPP
# define RPN_HPP

#include <stack>
#include <string>

class RPN {
    public:
        RPN();
        RPN(const RPN& other);
        RPN& operator=(const RPN& other);
        ~RPN();
        void loop(const char *input);
    private:
        void solver(const std::string &token);
        void operation(int opSpecifier);
        std::stack<int> numberStack;
        static const std::string operators;
}   ;

#endif