#include "scanner.h"
#include <iostream>
#include <fstream>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
        return 1;
    }
    std::ifstream file(argv[1]);
    std::string source_code((std::istreambuf_iterator<char>(file)),
                            std::istreambuf_iterator<char>());
    Scanner scanner(source_code);
    while (scanner.hasMoreTokens()) {
        std::cout << scanner.nextToken() << std::endl;
    }
    return 0;
}