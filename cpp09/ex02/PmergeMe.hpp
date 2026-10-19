#ifndef PMERGE_HPP
# define PMERGE_HPP

#include <vector>

#define FIRST 0
#define SECOND 1

class PmergeMe {
    private:
        std::vector<int > arr;
    public:
        PmergeMe();
        PmergeMe(std::vector<int>& input);
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe(); 
        void insertion(unsigned int groupSize, unsigned int elemSize, unsigned int remainder);
        void recursionLoop(int step);
        void merge(unsigned int groupSize, unsigned int elemSize, unsigned int remainder);
        void printArr();
} ;

#endif