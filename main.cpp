#include "FileReader.h"
#include "BruteForce.h"
#include "FirstFit.h"
#include "NextFit.h"
#include "BestFit.h"
#include <iostream>
#include <algorithm>

int main() {
    FileReader fileReader;
    std::vector<double> items = fileReader.readItems("items.txt");

    // Sort items for offline algorithms
    std::vector<double> sortedItems(items);
    std::sort(sortedItems.begin(), sortedItems.end(), std::greater<double>());
    std::cout << "Sorted items: ";
    for (double item : sortedItems) {
        std::cout << std::fixed << item << " ";
    }
    std::cout << std::endl;
    

    // Instantiate algorithms
    BruteForce bruteForce;
    FirstFit firstFit;
    NextFit nextFit;
    BestFit bestFit;

    // Execute algorithms
    int bruteForceBins = bruteForce.packItems(sortedItems); // For BruteForce, we can use the sorted list
    int firstFitBins = firstFit.packItems(items);
    int nextFitBins = nextFit.packItems(items);
    int bestFitBins = bestFit.packItems(items);
    int offlineFirstFitBins = firstFit.packItems(sortedItems);
    int offlineBestFitBins = bestFit.packItems(sortedItems);

    // Output results
    std::cout << "Total items: " << items.size() << std::endl;
    std::cout << "Brute Force Bins: " << bruteForceBins << std::endl;
    std::cout << "Online First Fit Bins: " << firstFitBins << std::endl;
    std::cout << "Online Next Fit Bins: " << nextFitBins << std::endl;
    std::cout << "Online Best Fit Bins: " << bestFitBins << std::endl;
    std::cout << "Offline First Fit Bins: " << offlineFirstFitBins << std::endl;
    std::cout << "Offline Best Fit Bins: " << offlineBestFitBins << std::endl;

    return 0;
}
