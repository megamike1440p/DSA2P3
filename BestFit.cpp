#include "BestFit.h"
#include <iostream> // For debug output
#include <cmath>    // For std::fabs
#include <iomanip>

int BestFit::packItems(const std::vector<double>& items) {
    const double epsilon = 1e-6; // A small value for floating-point comparison
    std::vector<Bin> bins;

    for (double item : items) {
        int bestBinIndex = -1;
        double minSpaceLeft = 1.0;

        for (size_t i = 0; i < bins.size(); ++i) {
            double spaceLeft = 1.0 - bins[i].getCurrentSize();
            // Use epsilon to check for "close enough" equality
            if (std::fabs(spaceLeft - item) < epsilon) {
                bestBinIndex = i;
                break; // Exact fit found, break early
            } else if (item < spaceLeft && spaceLeft - item < minSpaceLeft) {
                minSpaceLeft = spaceLeft - item;
                bestBinIndex = i;
            }
        }

        if (bestBinIndex != -1) {
            bins[bestBinIndex].addItem(item);
        } else {
            Bin newBin;
            newBin.addItem(item);
            bins.push_back(newBin);
        }

        // Debug output for each item placement
        std::cout << "Item " << item << " placed in bin " 
                  << (bestBinIndex != -1 ? bestBinIndex : bins.size() - 1) << std::endl;
        for (size_t i = 0; i < bins.size(); ++i) {
            std::cout << "Bin " << i << ": (Current Size: " << bins[i].getCurrentSize() << ") ";
            for (double binItem : bins[i].getItems()) {
                std::cout << std::fixed << std::setprecision(2) << binItem << " ";
            }
            std::cout << std::endl;
        }
    }

    return bins.size();
}
