#ifndef SCANNER_H
#define SCANNER_H

#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <set>

class Scanner {
private:
    std::stringstream input;
    std::string dfa;
    std::map<std::pair<std::string, char>, std::string> transitions;
    std::set <std::string> accepting_states;
    std::set <std::string> states = {};
public:
    Scanner(const std::string& text);
    void dfaBuilder(std::stringstream &stream);
    std::stringstream scanInput();
    void maximalMunch();
};

#endif