//
//  01-01.cpp
//  aoc-23
//
//  Created by Pavlin Panayotov on 12.12.23.
//

#include "01-01.hpp"
#include <fstream>
#include <iostream>

using namespace std;

void task01_01() {
    ifstream file("01-input.in");
    
    if (!file.is_open()) {
        perror("Error");
        return;
    }
    
    int sum = 0;
    string line;
    
    while(getline(file, line)) {
        int firstNum = -1;
        int lastNum = -1;
        
        for (size_t i = 0; i < line.length(); ++i) {
            char character = line[i];
            
            if (isdigit(character)) {
                firstNum = character - '0';
                break;
            }
        }
        
        if (firstNum < 0) {
            continue;
        }
        
        for (size_t i = line.length() - 1; i >= 0; i--) {
            char character = line[i];
            
            if (isdigit(character)) {
                lastNum = character - '0';
                break;
            }
        }
        
        if (lastNum >= 0) {
            sum += firstNum * 10 + lastNum;
        }
    }
    
    // sum = 54708
    cout << "Sum: " << sum << endl;
}
