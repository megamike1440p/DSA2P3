#include "BestFit.h"
#include <iostream> // For debug output

int BestFit::packItems(const std::vector<double>& items) {
    std::vector<Bin> bins;

    for (double item : items) {
        int bestBinIndex = -1;
        double minSpaceLeft = 1.0;

        for (size_t i = 0; i < bins.size(); ++i) {
            double spaceLeft = 1.0 - bins[i].getCurrentSize();
            // Check for an exact fit
            if (item == spaceLeft) {
                bestBinIndex = i;
                break; // Found the perfect fit, no need to look further
            }
            else if (item < spaceLeft && spaceLeft - item < minSpaceLeft) {
                minSpaceLeft = spaceLeft - item;
                bestBinIndex = i;
            }
        }

        // If a suitable bin is found, place the item there
        if (bestBinIndex != -1) {
            bins[bestBinIndex].addItem(item);
        } else {
            // Otherwise, create a new bin for the item
            Bin newBin;
            newBin.addItem(item);
            bins.push_back(newBin);
        }

        // Debug output for each item placement
        std::cout << "Item " << item << " placed in bin " 
                  << (bestBinIndex != -1 ? bestBinIndex : bins.size() - 1) << std::endl;
        for (size_t i = 0; i < bins.size(); ++i) {
            std::cout << "Bin " << i << " contains: ";
            for (double binItem : bins[i].getItems()) {
                std::cout << binItem << " ";
            }
            std::cout << std::endl;
        }
    }

    return bins.size();
}
