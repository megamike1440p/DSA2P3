#ifndef BIN_H
#define BIN_H

#include <vector>

class Bin {
private:
    std::vector<double> items;
    double capacity;
    double currentSize;

public:
    Bin() : capacity(1.0), currentSize(0.0) {}
    bool addItem(double size);
    double getCurrentSize() const;
    const std::vector<double>& getItems() const;
};

#endif // BIN_H