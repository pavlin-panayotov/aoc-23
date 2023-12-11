//
//  01-02.cpp
//  aoc-23
//
//  Created by Pavlin Panayotov on 12.12.23.
//

#include "01-02.hpp"
#include <fstream>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

map<char, vector<string>> mapFirstLetters(map<string, int> input) {
    map<char, vector<string>> result = {};
    
    for (auto const& [key, val] : input)
    {
        char firstLetter = key.front();
        vector<string>& values = result[firstLetter];
        values.push_back(key);
    }
    
    return result;
}

map<char, vector<string>> mapLastLetters(map<string, int> input) {
    map<char, vector<string>> result = {};
    
    for (auto const& [key, val] : input)
    {
        char firstLetter = key.back();
        vector<string>& values = result[firstLetter];
        values.push_back(key);
    }
    
    return result;
}


map<string, int> stringToNumber = {
    {
        "one", 1
    },
    {
        "two", 2
    },
    {
        "three", 3
    },
    {
        "four", 4
    },
    {
        "five", 5
    },
    {
        "six", 6
    },
    {
        "seven", 7
    },
    {
        "eight", 8
    },
    {
        "nine", 9
    },
};

map<char, vector<string>> firstLettersMap = mapFirstLetters(stringToNumber);
map<char, vector<string>> lastLettersMap = mapLastLetters(stringToNumber);

void printMap(map<char, vector<string>> map) {
    for (auto const& [key, val] : map)
    {
        cout << key << "; size=" << val.size() << endl;
    }
}

int findFirstNumber(string line) {
    for (size_t i = 0; i < line.length(); ++i) {
        char character = line[i];
        
        if (isdigit(character)) {
            int firstNum = character - '0';
            return firstNum;
        }
        
        auto it = firstLettersMap.find(character);
        
        if (it == firstLettersMap.end()) {
            continue;
        }
        
        for (const string& element : it->second) {
            string match = line.substr(i, element.length());
            auto number = stringToNumber.find(match);
            
            if (number != stringToNumber.end()) {
                return number->second;
            }
        }
    }
    
    return -1;
}

int findLastNumber(string line) {
    for (size_t i = line.length() - 1; i >= 0; i--) {
        char character = line[i];
        
        if (isdigit(character)) {
            return character - '0';
        }
        
        auto it = lastLettersMap.find(character);
        
        if (it == lastLettersMap.end()) {
            continue;
        }
        
        for (const string& element : it->second) {
            long long start = i - element.length() + 1;
            
            if (start < 0) {
                continue;
            }
            
            string match = line.substr(start, element.length());
            auto number = stringToNumber.find(match);
            
            if (number != stringToNumber.end()) {
                return number->second;
            }
        }
    }
    
    return -1;
}

void task01_02() {
    ifstream file("01-input.in");
    
    if (!file.is_open()) {
        perror("Error");
        return;
    }
    
    int sum = 0;
    string line;
    
    while(getline(file, line)) {
        int firstNum = findFirstNumber(line);
        
        if (firstNum < 0) {
            continue;
        }
        
        int lastNum = findLastNumber(line);
        
        if (lastNum >= 0) {
            sum += firstNum * 10 + lastNum;
        }
    }
    
    // sum = 54087
    cout << "Sum: " << sum << endl;
}
