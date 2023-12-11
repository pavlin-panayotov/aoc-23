//
//  02-01.cpp
//  aoc-23
//
//  Created by Pavlin Panayotov on 12.12.23.
//

#include "02-01.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include "../utils/strings.hpp"
#include "./02-helpers.hpp"

using namespace std;

void task02_01() {
    ifstream file("02-input.in");
    
    if (!file.is_open()) {
        perror("Error");
        return;
    }
    
    Cubes input = Cubes("12 red, 13 green, 14 blue");
    string line;
    int sum = 0;
    
    while(getline(file, line)) {
        vector<string> lineParts = splitString(line, ':');
        
        if (lineParts.size() != 2) {
            continue;
        }
        
        vector<string> gameParts = splitString(lineParts[0], ' ');
        
        if (gameParts.size() != 2) {
            continue;
        }
        
        int gameNumber = stoi(gameParts[1]);
        
        vector<string> drawsString = splitString(lineParts[1], ';');
        vector<Cubes> draws;
        
        for (const string& rawDraw : drawsString) {
            string drawString = trim(rawDraw);
            Cubes draw = Cubes(drawString);
            draws.push_back(draw);
        }
        
        Cubes result = combineCubes(draws);
        
        if (result.isSubsetOf(input)) {
            sum += gameNumber;
        }
    }
    
    // sum = 2285
    cout << "Sum: " << sum << endl;
}
