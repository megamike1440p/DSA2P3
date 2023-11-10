#ifndef BRUTEFORCE_H
#define BRUTEFORCE_H

#include <vector>

class BruteForce {
public:
    int packItems(std::vector<double> items);
private:
    void permute(std::vector<double>& items, int k, int size, int& minBins);
    int packWithNextFit(const std::vector<double>& items);
};

#endif // BRUTEFORCE_H