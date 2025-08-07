#ifndef SCANNER_H
#define SCANNER_H

#include <string>
#include <vector>
#include <sstream>

class Scanner {
private:
    std::stringstream input;
public:
    Scanner(const std::string& text);
    void scanInput();
};

#endif