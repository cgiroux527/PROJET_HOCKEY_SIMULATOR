#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <istream>

class Parser {
private:
    std::vector<std::vector<std::string>> _data;

public:
    Parser() = default;
    virtual void parse(std::istream& in) = 0;
    void clear();

    size_t getNumRows() const;
    size_t getNumCols(size_t row) const;

    std::string getString(size_t row, size_t col) const;
    int getInt(size_t row, size_t col) const;
};