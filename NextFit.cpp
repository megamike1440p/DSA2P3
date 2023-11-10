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

        for (size_t i = 0; i < bins.size(); ++i) {
            std::cout << "\tBin " << i << ": ";
            for (double binItem : bins[i].getItems()) {
                std::cout << std::fixed << std::setprecision(2) << binItem << " ";
            }
            std::cout << std::endl;
        }
    
    
    return bins.size();
}
