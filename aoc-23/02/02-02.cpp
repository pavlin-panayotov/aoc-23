//
//  02-02.cpp
//  aoc-23
//
//  Created by Pavlin Panayotov on 12.12.23.
//

#include "02-02.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include "../utils/strings.hpp"
#include "./02-helpers.hpp"

using namespace std;

void task02_02() {
    ifstream file("02-input.in");
    
    if (!file.is_open()) {
        perror("Error");
        return;
    }
    
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
        
        vector<string> drawsString = splitString(lineParts[1], ';');
        vector<Cubes> draws;
        
        for (const string& rawDraw : drawsString) {
            string drawString = trim(rawDraw);
            Cubes draw = Cubes(drawString);
            draws.push_back(draw);
        }
        
        Cubes result = combineCubes(draws);
        
        sum += result.green * result.blue * result.red;
    }
    
    // sum = 77021
    cout << "Sum: " << sum << endl;
}
