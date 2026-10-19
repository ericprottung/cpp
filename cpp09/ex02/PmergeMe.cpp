#include "PmergeMe.hpp"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>


PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(std::vector<int>& input) {
    arr = input;
}
PmergeMe::PmergeMe(const PmergeMe& other) {(void)other;}
PmergeMe& PmergeMe::operator=(const PmergeMe& other) {(void)other; return *this;}
PmergeMe::~PmergeMe() {}

void PmergeMe::printArr() {
    for (unsigned int i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << ", ";
    }
}

std::vector<int>    jacobsSeq(const unsigned int size) { 
    std::vector<int> jacobs;
    std::vector<int> full;
    jacobs.push_back(1); 
    jacobs.push_back(1);
    full.push_back(1);
    while (full.size() < size) {
        full.push_back(2 * (jacobs.at(jacobs.size() - 2)) + jacobs.at(jacobs.size() - 1));
        jacobs.push_back(2 * (jacobs.at(jacobs.size() - 2)) + jacobs.at(jacobs.size() - 1));
        
        for (int j = jacobs.at(jacobs.size() - 1) - 1; j > jacobs.at(jacobs.size() - 2); --j)
            full.push_back(j);
    }
    for (unsigned int i = 0; i < full.size(); ++i) {
        if ((unsigned int)full[i] > size) {
            full.erase(full.begin() + i, full.begin() + i + 1);
            --i;
        }
    }
    return full;
}

typedef struct s_loser {
    std::vector<int> block;   
    int winnerKey;            
} t_loser;

void PmergeMe::insertion(unsigned int groupSize, unsigned int elemSize, unsigned int remainder) {
    if (arr.size() / groupSize <= 1)
        return ;
    std::vector<int> jacobs = jacobsSeq(arr.size() / groupSize - 1);
    std::vector<t_loser> losers;
    
    for (unsigned int i = jacobs.size() * groupSize; i >= groupSize; i -= groupSize) {
        t_loser entry;
        entry.block.insert(entry.block.end(), arr.begin() + i, arr.begin() + i + elemSize);
        entry.winnerKey = arr.at(i + groupSize - 1);
        losers.push_back(entry);
        arr.erase(arr.begin() + i, arr.begin() + i + elemSize);
    }
    for (unsigned int i = 0; i < jacobs.size(); ++i) {
        t_loser &loser = losers.at(jacobs.at(i) - 1);
        std::vector<int>::iterator winnerPos = std::find(arr.begin(), arr.end(), loser.winnerKey);
        int winnerIdx = winnerPos - arr.begin();
        int half = elemSize;
        int loserVal = loser.block.back();
        
        int lo = 0;
        int hi = winnerIdx / half;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (arr[mid * half + half - 1] < loserVal)
                lo = mid + 1;
            else
                hi = mid;
        }
        arr.insert(arr.begin() + lo * half, loser.block.begin(), loser.block.end());
    }
    if (remainder < elemSize)
        return ;
    for (unsigned int j = 0; j < arr.size() - remainder; j += elemSize) {
        if (arr[arr.size() - remainder + elemSize - 1] < arr[j + elemSize - 1]) {
            std::vector<int> shift(arr.end() - remainder, arr.end() - remainder + elemSize);
            arr.erase(arr.end() - remainder, arr.end() - remainder + elemSize);
            arr.insert(arr.begin() + j, shift.begin(), shift.end());
            break;
        } 
    }
}

void PmergeMe::merge(unsigned int groupSize, unsigned int elemSize, unsigned int remainder) {
    for (unsigned int i = 0; i < arr.size() - remainder; i+= groupSize) {
        if (arr[i + elemSize - 1] > arr[i + groupSize - 1]) {
            arr.insert(arr.begin() + i + groupSize, arr.begin() + i, arr.begin() + i + elemSize);
            arr.erase(arr.begin() + i, arr.begin() + i + elemSize);
        }
    }
}

void PmergeMe::recursionLoop(int step) {
    
    unsigned int groupSize = 1 << step;
    unsigned int elemSize = groupSize / 2;
    unsigned int remainder = arr.size() % groupSize;
    
    if (groupSize > arr.size() - remainder)
        return ;
    merge(groupSize, elemSize, remainder);
    recursionLoop(step + 1);
    insertion(groupSize, elemSize, remainder);
    return ;
}