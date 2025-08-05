#ifndef SCANNER_H
#define SCANNER_H

#include <string>
#include <vector>

class Scanner {
private:
    std::string input;
    int position;
    
public:
    Scanner(const std::string& text);
    std::string nextToken();
    bool hasMoreTokens();
};

#endif