#include "scanner.h"
#include <iostream>
#include <fstream>
#include <sstream>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
        return 1;
    }
    std::ifstream file(argv[1]);
    std::string source_code("int main(int a, int b) { return 241; }");
    Scanner scanner(source_code);
    std::stringstream input = scanner.scanInput();
    return 0;
}