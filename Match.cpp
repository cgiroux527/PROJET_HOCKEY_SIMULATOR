//
// Created by Utilisateur on 2026-04-29.
//

#include "Match.h"

Match::Match(std::string nomEquipe, int overall) {
    _nomEquipe = nomEquipe;
    _overall = overall;
}

const std::string &Match::getNomEquipe() const {
    return _nomEquipe;
}

int Match::getOverall() const {
    return _overall;
}
