//
// Created by Utilisateur on 2026-03-18.
//

#include "CSVParser.h"

#include "fonctions.h"

CSVParser::CSVParser(char delimiter, bool readColumnNames) {
    setDelimiter(delimiter);
    setReadsColumnNames(readColumnNames);
}

char CSVParser::getDelimiter() const {
    return _delimiter;
}

const std::vector<std::string> &CSVParser::getColumnNames() const {
    return _columnNames;
}

const std::vector<std::vector<std::string> > &CSVParser::getData() const {
    return _data;
}

void CSVParser::setDelimiter(char delimiter) {
    _delimiter = delimiter;
}

bool CSVParser::readsColumnNames() const {
    return _readsColumnNames;
}

void CSVParser::setReadsColumnNames(bool readsColumnNames) {
    _readsColumnNames = readsColumnNames;
}

void CSVParser::parse(std::istream &in) {
    _data.clear();
    _columnNames.clear();

    std::string line;
    if (readsColumnNames()) {
        std::getline(in,line);
        _columnNames = split(line,';');
    }
    while (std::getline(in,line)) {
        _data.push_back(split(line,';'));
    }
}

int CSVParser::getColumnIndex(const std::string &columnName) const {

    for (size_t i = 0; i < getColumnNames().size(); i++) {
        if (columnName == getColumnNames()[i]) {
            return i;
        }
    }
    throw std::invalid_argument("Aucune colonne n'a été trouvé à l'indice");
}

const std::vector<std::string> &CSVParser::getRow(size_t index) const {
    for (size_t i = 0; i < _data.size(); i++) {
        if (i == index) {
            return _data[i];
        }
    }
    throw std::out_of_range("Indice invalide");
}

const std::string &CSVParser::getString(size_t row, size_t column) const {
    if (row < _data.size() && column < _data[row].size()) {
        return _data[row][column];
    }
    throw std::out_of_range("Indices invalide");
}

const std::string &CSVParser::getString(size_t row, const std::string &columnName) const {
    for (size_t i = 0; i < columnName.size(); i++) {
        if (columnName == _columnNames[i] && row < _data.size()) {
            return _data[row][i];
        }
    }
    throw std::out_of_range("Indices invalide");
}

int CSVParser::getInt(size_t row, size_t column) const {
    return std::stoi(getString(row,column));
}

int CSVParser::getInt(size_t row, const std::string &columnName) const {
    return std::stoi(getString(row,columnName));
}

double CSVParser::getDouble(size_t row, size_t column) const {
    return std::stod(getString(row,column));
}

double CSVParser::getDouble(size_t row, const std::string &columnName) const {
    return std::stod(getString(row,columnName));
}

size_t CSVParser::getNumRows() const {
    return _data.size();
}

size_t CSVParser::getNumColumns() const {
    return _data[1].size();
}

