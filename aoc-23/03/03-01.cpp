//
//  03-01.cpp
//  aoc-23
//
//  Created by Pavlin Panayotov on 12.12.23.
//

#include "03-01.hpp"
#include <fstream>
#include <iostream>
#include "../utils/strings.hpp"
#include "./03-helpers.hpp"

using namespace std;

bool isSymbol(char c) {
    return c != '.' && c != '\0' && !isdigit(c);
}

bool hasSymbolOnLine(string line, Number number) {
    size_t start = number.index == 0 ? 0 : number.index - 1;
    size_t numberEnd = number.endIndex();
    size_t end = numberEnd == line.length() - 1 ? numberEnd - 1 : numberEnd;
    
    for (size_t i = start; i <= end; i++) {
        char c = line[i];
        
        if (isSymbol(c)) {
//            cout << line << " " << i << "[" << c << "]" << endl;
            return true;
        }
    }
    
    return false;
}

bool shouldAddNumber(vector<string> lines, Number number) {
    // check top line
    if (number.row > 0) {
        if (hasSymbolOnLine(lines[number.row - 1], number)) {
            return true;
        }
    }
    
    // check current line
    if (number.index > 0 && isSymbol(lines[number.row][number.index - 1])) {
        return true;
    }
    
    if (number.endIndex() < lines[number.row].length() - 1 && isSymbol(lines[number.row][number.endIndex()])) {
        return true;
    }
    
    // check bottom line
    if (number.row < lines.size() - 1) {
        if (hasSymbolOnLine(lines[number.row + 1], number)) {
            return true;
        }
    }
    
    
    return false;
}

void task03_01() {
    ifstream file("03-input.in");
    
    if (!file.is_open()) {
        perror("Error");
        return;
    }
    
    string line;
    vector<Number> parts;
    vector<string> lines;
    
    
    while(getline(file, line)) {
        
        cout << line << endl;
        
        size_t lineNumber = lines.size();
        lines.push_back(line);
        
        string acc = "";
        
        for (size_t i = 0; const auto& c : line) {
            if (isdigit(c)) {
                acc += c;
            } else if (acc.length()) {
                parts.push_back(Number(acc, i - acc.length(), lineNumber));
                acc = "";
            }
            
            ++i;
        }
        
        if (acc.length()) {
            parts.push_back(Number(acc, line.length() - acc.length(), lineNumber));
        }
    }
    
    cout << "********************" << endl << endl;
    
    int sum = 0;
    
    for (const auto& number : parts) {
        if (shouldAddNumber(lines, number)) {
            sum += stoi(number.value);
            cout << number.value << endl;
        }
    }
    
    // sum = 535351
    cout << "Sum: " << sum << endl;
}
