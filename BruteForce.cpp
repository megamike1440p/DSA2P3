#include "BruteForce.h"
#include "NextFit.h"
#include <algorithm>

int BruteForce::packItems(std::vector<double> items) {
    int minBins = items.size();
    permute(items, 0, items.size(), minBins);
    return minBins;
}

void BruteForce::permute(std::vector<double>& items, int k, int size, int& minBins) {
    if (k == size - 1) {
        minBins = std::min(minBins, packWithNextFit(items));
    } else {
        for (int i = k; i < size; i++) {
            std::swap(items[k], items[i]);
            permute(items, k + 1, size, minBins);
            std::swap(items[k], items[i]);
        }
    }
}

int BruteForce::packWithNextFit(const std::vector<double>& items) {
    NextFit nextFitAlgorithm;
    return nextFitAlgorithm.packItems(items);
}