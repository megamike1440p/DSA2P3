#include "BruteForce.h"

int BruteForce::packItems(std::vector<double> items) {
    // Sort the items in ascending order to generate permutations correctly
    std::sort(items.begin(), items.end());
    int minBins = items.size(); // Initialize with the maximum possible number of bins
    std::vector<std::vector<double>> bestConfiguration;

    do {
        std::vector<Bin> currentBins;
        int currentBinCount = packPermutation(items, currentBins);
        if (currentBinCount < minBins) {
            minBins = currentBinCount;
            bestConfiguration.clear();
            for (const Bin& bin : currentBins) {
                bestConfiguration.push_back(bin.getItems());
            }
        }
    } while (std::next_permutation(items.begin(), items.end()));

    // Print the best bin configuration

    for (size_t i = 0; i < bestConfiguration.size(); ++i) {
            std::cout << "\tBin " << i << ": ";
            for (double binItem : bestConfiguration[i]) {
                std::cout << std::fixed << std::setprecision(2) << binItem << " ";
            }
            std::cout << std::endl;
        }
    
    return minBins;
}

int BruteForce::packPermutation(const std::vector<double>& items, std::vector<Bin>& bins) {
    for (double item : items) {
        bool placed = false;
        for (Bin& bin : bins) {
            if (bin.addItem(item)) {
                placed = true;
                break;
            }
        }
        if (!placed) {
            Bin newBin;
            newBin.addItem(item);
            bins.push_back(newBin);
        }
    }
    return bins.size();
}
