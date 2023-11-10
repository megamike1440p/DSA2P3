#include "BestFit.h"
#include <iostream> // For debug output

int BestFit::packItems(const std::vector<double>& items) {
    std::vector<Bin> bins;

    for (double item : items) {
        int bestBinIndex = -1;
        double minSpaceLeft = 1.0; // Start with the maximum space a bin can have.

        for (size_t i = 0; i < bins.size(); ++i) {
    double spaceLeft = 1.0 - bins[i].getCurrentSize();
    // Check for an exact fit first
    if (item == spaceLeft) {
        bestBinIndex = i;
        break; // Break out of the loop as we've found the perfect bin
    }
    // Otherwise, find the bin with the least space left after placement
    else if (item < spaceLeft && spaceLeft < minSpaceLeft) {
        minSpaceLeft = spaceLeft;
        bestBinIndex = i;
    }
}

        // If a suitable bin is found, place the item there.
        if (bestBinIndex != -1) {
            bins[bestBinIndex].addItem(item);
        } else {
            // Otherwise, create a new bin for the item.
            Bin newBin;
            newBin.addItem(item);
            bins.push_back(newBin);
        }
    }

    return bins.size();
}
