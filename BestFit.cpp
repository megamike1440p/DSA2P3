#include "BestFit.h"

int BestFit::packItems(const std::vector<double>& items) {
    std::vector<Bin> bins;

    // Iterate over each item to place it in the best bin
    for (double item : items) {
        int bestBinIndex = -1;
        double minSpaceLeft = 1.0;

        // Find the bin that after placing the item will have the least space left
        for (size_t i = 0; i < bins.size(); ++i) {
            double spaceLeft = 1.0 - bins[i].getCurrentSize();
            if (item <= spaceLeft && spaceLeft < minSpaceLeft) {
                minSpaceLeft = spaceLeft;
                bestBinIndex = i;
            }
        }

        // If we found a suitable bin, place the item there
        if (bestBinIndex != -1) {
            bins[bestBinIndex].addItem(item);
        } else {
            // Otherwise, create a new bin for the item
            Bin newBin;
            newBin.addItem(item);
            bins.push_back(newBin);
        }
    }

    // Return the number of bins used
    return bins.size();
}