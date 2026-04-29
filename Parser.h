#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <istream>

class Parser {

public:
    virtual void parse(std::istream& in) = 0;
};