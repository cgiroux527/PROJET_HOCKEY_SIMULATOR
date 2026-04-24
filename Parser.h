#pragma once

#include <iostream>

class Parser {
public:
    virtual void parse(std::istream& in) = 0;
};