#include "Bin.h"

bool Bin::addItem(double size) {
    if (currentSize + size <= capacity) {
        items.push_back(size);
        currentSize += size;
        return true;
    }
    return false;
}

double Bin::getCurrentSize() const {
    return currentSize;
}

const std::vector<double>& Bin::getItems() const {
    return items;
}