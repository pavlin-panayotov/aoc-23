//
//  04-01.cpp
//  aoc-23
//
//  Created by Pavlin Panayotov on 13.12.23.
//

#include "04-01.hpp"
#include <fstream>
#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include "../utils/strings.hpp"

using namespace std;

set<string> parseNumbers(string numbers) {
    vector<string> parsed = splitString(numbers, ' ');
    set<string> result;
    
    for (const auto& number : parsed) {
        string trimmed = trim(number);
        
        if (trimmed.length()) {
            result.insert(trimmed);
        }
    }
    
    return result;
}

struct Game {
    set<string> winning, numbers;
    
    Game(string line) {
        vector<string> parts = splitString(splitString(line, ':')[1], '|');
        this->winning = parseNumbers(parts[0]);
        this->numbers = parseNumbers(parts[1]);
    }
    
    int score() const {
        int matches = 0;
        
        for (const auto& number : winning) {
            if (numbers.contains(number)) {
                ++matches;
            }
        }
        
        if (matches == 0) {
            return 0;
        }
        
        return pow(2, matches - 1);
    }
};

void task04_01() {
    ifstream file("04-input.in");
    
    if (!file.is_open()) {
        perror("Error");
        return;
    }
    
    int sum = 0;
    string line;
    
    while(getline(file, line)) {
//        cout << line << endl;
        
        Game game(line);
        sum += game.score();
    }
    
    // sum = 25010
    cout << "Sum: " << sum << endl;
}

