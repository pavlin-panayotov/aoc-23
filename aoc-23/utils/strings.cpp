//
//  strings.cpp
//  aoc-23
//
//  Created by Pavlin Panayotov on 12.12.23.
//

#include "strings.hpp"
#include <string>
#include <sstream>

using namespace std;

vector<string> splitString(const string& s, char delimiter) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    
    while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    
    return tokens;
}

string trim(const string& str) {
    size_t start = str.find_first_not_of(" \t\r\n");
    size_t end = str.find_last_not_of(" \t\r\n");
    
    if (start == string::npos) {
        // String contains only whitespace
        return "";
    }
    
    return str.substr(start, end - start + 1);
}
