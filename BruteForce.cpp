#include "BruteForce.h"
#include <algorithm> // for std::next_permutation
#include <iostream>  // for std::cout
#include <iomanip>   // for std::setprecision

int BruteForce::packItems(std::vector<double> items) {
    std::sort(items.begin(), items.end());
    int minBins = items.size(); // Start with the maximum possible bins

    do {
        std::vector<Bin> currentBins;
        int currentBinCount = packPermutation(items, currentBins);
        if (currentBinCount < minBins) {
            minBins = currentBinCount;
            bestConfiguration = currentBins; // Update the best configuration
        }
    } while (std::next_permutation(items.begin(), items.end()));
    for (size_t i = 0; i < bestConfiguration.size(); ++i) {
        std::cout << "\tBin " << i << ": ";
        for (double binItem : bestConfiguration[i].getItems()) {
            std::cout << std::fixed << std::setprecision(2) << binItem << " ";
        }
        std::cout << std::endl;
    }
    return minBins;
}

int BruteForce::packPermutation(std::vector<double>& items) {
    std::vector<Bin> bins;
    for (double item : items) {
        bool placed = false;
        for (Bin& bin : bins) {
            if (bin.addItem(item)) {
                placed = true;
                break;
            }
        }
        if (!placed) {
            bins.emplace_back();
            bins.back().addItem(item);
        }
    }
    return bins.size();
}
