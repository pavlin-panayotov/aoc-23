//
//  03-helpers.cpp
//  aoc-23
//
//  Created by Pavlin Panayotov on 12.12.23.
//

#include "03-helpers.hpp"

Number::Number(string value, size_t index, size_t row) {
    this->value = value;
    this->index = index;
    this->row = row;
}

string Number::description() const {
    return value + " [" + to_string(row) + ", " + to_string(index) + "]";
}

size_t Number::endIndex() const {
    return index + value.length();
}
