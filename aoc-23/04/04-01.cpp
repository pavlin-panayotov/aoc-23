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
#include "./04-helpers.hpp"

using namespace std;

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

