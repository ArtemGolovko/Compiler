#include "Reader.h"

namespace Utils
{
	std::string Reader::readfile(std::filesystem::path filePath)
	{
        std::ifstream fin;
        fin.exceptions(std::ifstream::badbit | std::ifstream::failbit);

        fin.open(filePath, std::ifstream::binary);

        const int file_size = std::filesystem::file_size(filePath);

        char* buffer = new char[file_size + 1]; buffer[file_size] = 0;
        fin.read(buffer, file_size);

        fin.close();

        std::string s(buffer);

        delete[]buffer;

        return s;
	}
}