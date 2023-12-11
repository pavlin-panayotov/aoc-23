//
//  02-helpers.cpp
//  aoc-23
//
//  Created by Pavlin Panayotov on 12.12.23.
//

#include "02-helpers.hpp"
#include <iostream>
#include "../utils/strings.hpp"

Cubes::Cubes() {
    blue = 0;
    red = 0;
    green = 0;
};

Cubes::Cubes(string input) {
    vector<string> draws = splitString(input, ',');
    blue = 0;
    red = 0;
    green = 0;
    
    for (const string& rawDraw : draws) {
        vector<string> drawParts = splitString(trim(rawDraw), ' ');
        
        if (drawParts.size() != 2) {
            continue;
        }
        
        int count = stoi(drawParts[0]);
        string color = trim(drawParts[1]);
        
        if (color == "red") {
            red = count;
        } else if (color == "blue") {
            blue = count;
        } else if (color == "green") {
            green = count;
        }
    }
}

void Cubes::print() const {
    cout << description() << endl;
}

string Cubes::description() const {
    return "blue(" + to_string(blue) + "), red(" + to_string(red) + "), green(" + to_string(green) + ")";
}

bool Cubes::isSubsetOf(Cubes cubes) {
    return cubes.green >= green && cubes.blue >= blue && cubes.red >= red;
}

Cubes combineCubes(vector<Cubes> cubes) {
    Cubes combined = Cubes();
    
    for (const auto& c : cubes) {
        combined.green = max(combined.green, c.green);
        combined.red = max(combined.red, c.red);
        combined.blue = max(combined.blue, c.blue);
    }
    
    return combined;
}
