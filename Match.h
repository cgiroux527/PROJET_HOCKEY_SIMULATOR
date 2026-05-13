//
// Created by Utilisateur on 2026-04-29.
//

#ifndef PROJET_HOCKEY_SIMULATOR_MATCH_H
#define PROJET_HOCKEY_SIMULATOR_MATCH_H

#include <string>

class Match {
private:
    std::string _nomEquipe;
    int _overall;

public:
    Match(const std::string &nomEquipe, int overall);

    const std::string& getNomEquipe() const;
    int getOverall() const;
};


#endif //PROJET_HOCKEY_SIMULATOR_MATCH_H