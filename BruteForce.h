#ifndef BRUTEFORCE_H
#define BRUTEFORCE_H

#include <vector>

class BruteForce {
public:
    int packItems(std::vector<double> items);

private:
    void permute(std::vector<double>& items, int start, int& minBins);
    int packPermutation(std::vector<double>& items);
};

#endif // BRUTEFORCE_H
