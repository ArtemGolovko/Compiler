#include <string>
#include <filesystem>
#include <fstream>

#ifndef UTILS_READER_H
#define UTILS_READER_H

namespace Utils {

    class Reader
    {
    public:
        static std::string readfile(std::filesystem::path filePath);
    };
}
#endif // UTILS_READER_H