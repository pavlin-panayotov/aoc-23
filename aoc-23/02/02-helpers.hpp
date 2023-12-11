//
//  02-helpers.hpp
//  aoc-23
//
//  Created by Pavlin Panayotov on 12.12.23.
//

#ifndef _2_helpers_hpp
#define _2_helpers_hpp

#include <stdio.h>
#include <string>

using namespace std;

struct Cubes {
    int blue, red, green;
    
    Cubes();
    Cubes(string input);
    
    void print() const;
    string description() const;
    bool isSubsetOf(Cubes cubes);
};

Cubes combineCubes(vector<Cubes> cubes);

#endif /* _2_helpers_hpp */
