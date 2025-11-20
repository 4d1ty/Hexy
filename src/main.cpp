#include <iostream>
#include <fstream>
#include <iomanip>
#include <cctype>

int main(int argc, char const *argv[])
{
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <input_file>\n";
        return 1;
    }

    std::ifstream file(argv[1], std::ios::binary);
    if(!file) {
        std::cerr << "Error: Could not open file " << argv[1] << "\n";
        return 1;
    }

    unsigned char line[16];
    int offset = 0;
    char byte;

    // Header
    std::cout << std::setw(9) << " ";
    for(int i=0; i<16; ++i)
        std::cout << std::setfill('0') << std::setw(2) << std::hex << i << " ";
    std::cout << "\n";

    while(file.get(byte)) {
        unsigned char ubyte = static_cast<unsigned char>(byte);
        line[offset % 16] = ubyte;

        if(offset % 16 == 0)
            std::cout << std::setfill('0') << std::setw(8) << std::hex << offset << " ";

        // Print hex byte
        std::cout << std::setfill('0') << std::setw(2) << std::hex << (int)ubyte << " ";
        ++offset;

        // End of line: print ASCII with colors
        if(offset % 16 == 0) {
            std::cout << " ";
            for(int i=0; i<16; ++i) {
                unsigned char c = line[i];
                if(std::isprint(c))
                    std::cout << "\033[32m" << c << "\033[0m"; // green printable
                else
                    std::cout << "\033[31m.\033[0m";          // red dot for non-printable
            }
            std::cout << "\n";
        }
    }

    // Handle last partial line
    if(offset % 16 != 0) {
        int remaining = 16 - (offset % 16);
        for(int i=0; i<remaining; ++i) std::cout << "   ";
        std::cout << " ";
        for(int i=0; i < offset % 16; ++i) {
            unsigned char c = line[i];
            if(std::isprint(c))
                std::cout << "\033[32m" << c << "\033[0m";
            else
                std::cout << "\033[31m.\033[0m";
        }
        std::cout << "\n";
    }

    return 0;
}
