#include "BestFit.h"
#include "Bin.h"
#include <vector>
#include <algorithm>

int BestFit::packItems(const std::vector<double>& items) {
    std::vector<Bin> bins;

    for (double item : items) {
        int bestBinIndex = -1;
        double bestFit = 1.0;

        for (size_t i = 0; i < bins.size(); ++i) {
            double spaceLeft = 1.0 - bins[i].getCurrentSize();
            if (item <= spaceLeft && spaceLeft < bestFit) {
                bestFit = spaceLeft;
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
    }

    return bins.size();
}