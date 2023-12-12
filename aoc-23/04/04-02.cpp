//
//  04-02.cpp
//  aoc-23
//
//  Created by Pavlin Panayotov on 13.12.23.
//

#include "04-02.hpp"
#include <fstream>
#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <map>
#include "./04-helpers.hpp"

using namespace std;

void task04_02() {
    ifstream file("04-input.in");
    
    if (!file.is_open()) {
        perror("Error");
        return;
    }
    
    int sum = 0;
    string line;
    int gameNumber = 1;
    map<int, int> cardsByGame;
    
    while(getline(file, line)) {
//        cout << line << endl;
        int cardsCount = cardsByGame[gameNumber] + 1;
        
        Game game(line);
        
//        cout << game.matches << " " << cardsCount << endl;
        
        for (int i = gameNumber + 1; i < gameNumber + game.matches + 1; ++i) {
            cardsByGame[i] = cardsByGame[i] + cardsCount;
        }
        
        sum += cardsCount;
        
        ++gameNumber;
    }
    
    // sum = 9924412
    cout << "Sum: " << sum << endl;
}
