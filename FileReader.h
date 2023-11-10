#ifndef FILEREADER_H
#define FILEREADER_H

#include <vector>
#include <string>

class FileReader {
public:
    std::vector<double> readItems(const std::string& filename);
};

#endif // FILEREADER_H