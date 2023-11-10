#include "BruteForce.h"
#include <algorithm> // for std::next_permutation

int BruteForce::packItems(std::vector<double> items) {
    // Sort the items in ascending order to generate permutations correctly
    std::sort(items.begin(), items.end());
    int minBins = items.size(); // Initialize with the maximum possible number of bins

    do {
        // Evaluate the current permutation
        minBins = std::min(minBins, packPermutation(items));
    } while (std::next_permutation(items.begin(), items.end()));

    return minBins;
}

int BruteForce::packPermutation(std::vector<double>& items) {
    std::vector<double> bins;
    for (double item : items) {
        bool placed = false;
        for (double &bin : bins) {
            if (bin + item <= 1.0) {
                // Place the item in the bin
                bin += item;
                placed = true;
                break;
            }
        }
        if (!placed) {
            // If the item was not placed in any bin, create a new bin
            bins.push_back(item);
        }
    }
    return bins.size();
}
