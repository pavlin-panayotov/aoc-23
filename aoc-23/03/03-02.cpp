//
//  03-02.cpp
//  aoc-23
//
//  Created by Pavlin Panayotov on 12.12.23.
//

#include "03-02.hpp"
#include <fstream>
#include <iostream>
#include <map>
#include "../utils/strings.hpp"
#include "./03-helpers.hpp"

using namespace std;

bool isStar(char c) {
    return c == '*';
}

string getStarId(size_t row, size_t index) {
    return to_string(row) + "." + to_string(index);
}

void checkStarsOnLine(string line, size_t row, Number number, map<string, vector<int>> &starToNumbers) {
    size_t start = number.index == 0 ? 0 : number.index - 1;
    size_t numberEnd = number.endIndex();
    size_t end = numberEnd == line.length() - 1 ? numberEnd - 1 : numberEnd;
    
    for (size_t i = start; i <= end; i++) {
        char c = line[i];
        
        if (isStar(c)) {
//            cout << line << " " << i << "[" << c << "]" << endl;
            starToNumbers[getStarId(row, i)].push_back(stoi(number.value));
        }
    }
}

void checkForStars(vector<string> lines, Number number, map<string, vector<int>> &starToNumbers) {
    // check top line
    if (number.row > 0) {
        checkStarsOnLine(lines[number.row - 1], number.row - 1, number, starToNumbers);
    }
    
    // check current line
    if (number.index > 0 && isStar(lines[number.row][number.index - 1])) {
        starToNumbers[getStarId(number.row, number.index - 1)].push_back(stoi(number.value));
    }
    
    if (number.endIndex() < lines[number.row].length() - 1 && isStar(lines[number.row][number.endIndex()])) {
        starToNumbers[getStarId(number.row, number.endIndex())].push_back(stoi(number.value));
    }
    
    // check bottom line
    if (number.row < lines.size() - 1) {
        checkStarsOnLine(lines[number.row + 1], number.row + 1, number, starToNumbers);
    }
}

void task03_02() {
    ifstream file("03-input.in");
    
    if (!file.is_open()) {
        perror("Error");
        return;
    }
    
    string line;
    vector<Number> parts;
    vector<string> lines;
    map<string, vector<int>> stars;
    
    while(getline(file, line)) {
//        cout << line << endl;
        
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
    
//    cout << "********************" << endl << endl;
    
    int sum = 0;
    
    for (const auto& number : parts) {
        checkForStars(lines, number, stars);
    }
    
    for (const auto& star : stars) {
        if (star.second.size() == 2) {
            sum += star.second[0] * star.second[1];
        }
    }
    
    // sum = 87287096
    cout << "Sum: " << sum << endl;
}
