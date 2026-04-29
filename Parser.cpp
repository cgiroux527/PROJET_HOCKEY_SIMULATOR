//
// Created by Utilisateur on 2026-03-18.
//

#include "Parser.h"
#include <sstream>
#include <iostream>

void Parser::clear() {
    _data.clear();
}

void Parser::parse(std::istream &in) {
    clear();

    std::string line;

    while (std::getline(in, line)) {
        if (line.empty()) continue;

        std::vector<std::string> row;
        std::stringstream ss(line);
        std::string cell;

        while (std::getline(ss, cell, ';')) {
            row.push_back(cell);
        }

        if (!row.empty()) {
            _data.push_back(row);
        }
    }
}

size_t Parser::getNumRows() const {
    return _data.size();
}

size_t Parser::getNumCols(size_t row) const {
    if (row >= _data.size()) return 0;
    return _data[row].size();
}

std::string Parser::getString(size_t row, size_t col) const {
    if (row >= _data.size()) return "";
    if (col >= _data[row].size()) return "";
    return _data[row][col];
}

int Parser::getInt(size_t row, size_t col) const {
    if (row >= _data.size()) return 0;
    if (col >= _data[row].size()) return 0;

    try {
        return std::stoi(_data[row][col]);
    } catch (...) {
        return 0;
    }
}