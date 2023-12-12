//
//  04-helpers.hpp
//  aoc-23
//
//  Created by Pavlin Panayotov on 13.12.23.
//

#ifndef _4_helpers_hpp
#define _4_helpers_hpp

#include <stdio.h>
#include <string>
#include <set>

using namespace std;

struct Game {
    set<string> winning, numbers;
    int matches;
    
    Game(string line);
    
    int score() const;
};


#endif /* _4_helpers_hpp */
