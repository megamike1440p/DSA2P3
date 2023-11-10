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

    // Instantiate algorithms
    BruteForce bruteForce;
    FirstFit firstFit;
    NextFit nextFit;
    BestFit bestFit;

    // Execute algorithms using the unsorted list for online algorithms
    std::cout << "Brute force fit bin order: " << std::endl;
    int bruteForceBins = bruteForce.packItems(sortedItems); // Assuming brute force uses sorted items
    std::cout << "Next fit bin order: " << std::endl;
    int onlineNextFitBins = nextFit.packItems(items);
    std::cout << "Online first fit bin order: " << std::endl;
    int onlineFirstFitBins = firstFit.packItems(items);
    std::cout << "Online best fit bin order: " << std::endl;
    int onlineBestFitBins = bestFit.packItems(items);
    std::cout << "Offline first fit bin order: " << std::endl;
    int offlineFirstFitBins = firstFit.packItems(sortedItems);
    std::cout << "Offline best fit bin order: " << std::endl;
    int offlineBestFitBins = bestFit.packItems(sortedItems); // Correct list for offline

    // Output results
    std::cout << "Total items: " << items.size() << std::endl;
    std::cout << "Brute Force Bins: " << bruteForceBins << std::endl;
    std::cout << "Online First Fit Bins: " << onlineFirstFitBins << std::endl;
    std::cout << "Online Next Fit Bins: " << onlineNextFitBins << std::endl;
    std::cout << "Online Best Fit Bins: " << onlineBestFitBins << std::endl;
    std::cout << "Offline First Fit Bins: " << offlineFirstFitBins << std::endl;
    std::cout << "Offline Best Fit Bins: " << offlineBestFitBins << std::endl;

    return 0;
}
