#ifndef BRUTEFORCE_H
#define BRUTEFORCE_H

#include <vector>
#include "Bin.h"
#include <iostream>
#include <iomanip>
#include <algorithm>

class BruteForce {
public:
    int packItems(std::vector<double> items);

private:
    void permute(std::vector<double>& items, int start, std::vector<std::vector<double>>& bestConfiguration, int& minBins);
    int packPermutation(const std::vector<double>& items, std::vector<Bin>& bins);
};

#endif // BRUTEFORCE_H
