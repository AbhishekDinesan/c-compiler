#include "scanner.h" 
#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <map>

std::string readFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        exit;
    }
    std::stringstream file_buffer;
    file_buffer << file.rdbuf();
    file.close();
    return file_buffer.str();
}

Scanner::Scanner(const std::string& text): input(text), transitions(), accepting_states(), states(){
  dfa = readFile("language.dfa");
} 

bool isChar(std::string s) {
  return s.length() == 1;
}
bool isRange(std::string s) {
  return s.length() == 3 && s[1] == '-';
}

void Scanner::dfaBuilder(std::stringstream &stream) {
  const std::string STATES      = ".STATES";
  const std::string TRANSITIONS = ".TRANSITIONS";
  std::string initialState;
  std::istream& in = stream;
  std::string s;
  while(in >> s) {
    if (s == TRANSITIONS) { 
      break; 
    } else {
      static bool initial = true;
      bool accepting = false;
      if (s.back() == '!' && !isChar(s)) {
        accepting = true;
        s.pop_back();
      }
      if (initial) {
        initialState = s;
        states.insert(s);
        if (accepting){
          accepting_states.insert(s);
        }
        initial = false;
      }
      if (accepting) {
        accepting_states.insert(s);
        states.insert(s);
      }
      //the regular ones
      if (!accepting && !initial){
        states.insert(s);
      }
    }
  }
  std::getline(in, s); 
  while(std::getline(in, s)) {
      std::string fromState, symbols, toState;
      std::istringstream line(s);
      std::vector<std::string> lineVec;
      while(line >> s) {
        lineVec.push_back(s);
      }
      fromState = lineVec.front();
      toState = lineVec.back();
      for(int i = 1; i < lineVec.size()-1; ++i) {
        std::string s = lineVec[i];
        if (isChar(s)) {
          symbols += s;
        } else if (isRange(s)) {
          for(char c = s[0]; c <= s[2]; ++c) {
            symbols += c;
          }
        }
      }
      for ( char c : symbols ) {
        transitions.insert({{fromState, c}, toState});
      }
}
}

void maximal_munch(){
  /*
  while there is input:
  // check if theres a transition
    //if there is a transition, do it
    // if it's accepting, then output the tokens

  // if the transition is in an accept


  */


}


std::stringstream Scanner::scanInput(){
    std::stringstream dfastream(dfa);
    dfaBuilder(dfastream);
    for (const auto& entry: transitions){ 
        const auto &key = entry.first;
        const auto &value = entry.second;
        const auto &from = key.first;
        const auto &c = key.second;
        std::cout << from << "--> " << c << "--> " << value << std::endl;
    }
    for (const auto& entry: states){
        std::cout << "i" << entry << std::endl;
    }
    return dfastream;
};

