//
//  03-helpers.hpp
//  aoc-23
//
//  Created by Pavlin Panayotov on 12.12.23.
//

#ifndef _3_helpers_hpp
#define _3_helpers_hpp

#include <stdio.h>
#include <string>

using namespace std;

struct Number {
    string value;
    size_t index, row;
    
    Number(string value, size_t index, size_t row);
    
    string description() const;
    size_t endIndex() const;
};

#endif /* _3_helpers_hpp */
