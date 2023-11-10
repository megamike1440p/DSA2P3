#include "NextFit.h"
#include "Bin.h"
#include <vector>

int NextFit::packItems(const std::vector<double>& items) {
    std::vector<Bin> bins;
    bins.emplace_back();

    Bin* lastBin = &bins.back();

    for (double item : items) {
        if (!lastBin->addItem(item)) {
            bins.emplace_back();
            lastBin = &bins.back();
            lastBin->addItem(item);
        }
    }
    return bins.size();
}
