#include "scanner.h" 
#include <iostream>

Scanner::Scanner(const std::string& text) : input(text), position(0) {
}

std::string Scanner::nextToken() {

    return "TOKEN";
}

bool Scanner::hasMoreTokens() {
    return position < input.length();
}