#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <vector>

static void subjectTest() {
    std::cout << "subject test MutantStack" << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
}

static void listTest() {
    std::cout << "same with std::list" << std::endl;
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(17);
    std::cout << lst.back() << std::endl;
    lst.pop_back();
    std::cout << lst.size() << std::endl;
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    //[...]
    lst.push_back(0);
    std::list<int>::iterator it = lst.begin();
    std::list<int>::iterator ite = lst.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::list<int> l(lst);
}

static void extraTests() {
    std::cout << "extra tests" << std::endl;

    MutantStack<int> empty;
    std::cout << "empty: begin == end -> " << (empty.begin() == empty.end()) << std::endl;

    MutantStack<int> big;
    for (int i = 0; i < 1000; i++)
        big.push(i);
    int expected = 0;
    bool ok = true;
    for (MutantStack<int>::iterator it = big.begin(); it != big.end(); ++it)
        if (*it != expected++)
            ok = false;
    std::cout << "1000 elements iterated in order -> " << (ok && expected == 1000) << std::endl;

    std::cout << "reverse:";
    MutantStack<int> small;
    small.push(1);
    small.push(2);
    small.push(3);
    for (MutantStack<int>::reverse_iterator it = small.rbegin(); it != small.rend(); ++it)
        std::cout << " " << *it;
    std::cout << std::endl;

    const MutantStack<int> copy(small);
    std::cout << "const copy:";
    for (MutantStack<int>::const_iterator it = copy.begin(); it != copy.end(); ++it)
        std::cout << " " << *it;
    std::cout << std::endl;

    MutantStack<int> assigned;
    assigned = small;
    *assigned.begin() = 42;
    std::cout << "deep copy (original unchanged) -> " << *small.begin()
              << ", copy -> " << *assigned.begin() << std::endl;

    MutantStack<int, std::vector<int> > vstack;
    vstack.push(10);
    vstack.push(20);
    std::cout << "with std::vector:";
    for (MutantStack<int, std::vector<int> >::iterator it = vstack.begin(); it != vstack.end(); ++it)
        std::cout << " " << *it;
    std::cout << std::endl;
}

int main()
{
    subjectTest();
    listTest();
    extraTests();
    return 0;
}
