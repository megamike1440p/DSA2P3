#include "FileReader.h"
#include <fstream>
#include <iostream>

std::vector<double> FileReader::readItems(const std::string& filename) {
    std::vector<double> items;
    std::ifstream file(filename);
    double size;

    if (!file) {
        std::cerr << "Unable to open file: " << filename << std::endl;
        return items;
    }

    while (file >> size) {
        if (size > 0 && size <= 1) {
            items.push_back(size);
        }
    }

    return items;
}