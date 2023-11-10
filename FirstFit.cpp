#include "FirstFit.h"
#include "Bin.h"
#include <vector>

int FirstFit::packItems(const std::vector<double>& items) {
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
            Bin newBin;
            newBin.addItem(item);
            bins.push_back(newBin);
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
