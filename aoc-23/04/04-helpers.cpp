//
//  04-helpers.cpp
//  aoc-23
//
//  Created by Pavlin Panayotov on 13.12.23.
//

#include "04-helpers.hpp"
#include "../utils/strings.hpp"

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

Game::Game(string line) {
    vector<string> parts = splitString(splitString(line, ':')[1], '|');
    this->winning = parseNumbers(parts[0]);
    this->numbers = parseNumbers(parts[1]);
    
    int matches = 0;
    for (const auto& number : winning) {
        if (numbers.contains(number)) {
            ++matches;
        }
    }
    this->matches = matches;
}

int Game::score() const {
    if (matches == 0) {
        return 0;
    }
    
    return pow(2, matches - 1);
}
