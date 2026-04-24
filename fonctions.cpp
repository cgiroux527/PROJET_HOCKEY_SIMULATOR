//
// Created by Utilisateur on 2026-03-18.
//

#include "fonctions.h"

std::vector<std::string> split(const std::string& str, char delimiter) {
    std::vector<std::string> result;

    std::string acc;

    for (size_t i = 0; i < str.size(); i++) {
        if (str[i] != delimiter) {
            acc += str[i];
        } else {
            result.push_back(acc);
            acc = "";
        }
    }
    result.push_back(acc);
    return result;
}