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
    Match(std::string nomEquipe, int overall);

    int getNomEquipe();
    const std::string& getOverall();

    void setNomEquipe(const std::string& nomEquipe);
    void setOverall(int overall);

};


#endif //PROJET_HOCKEY_SIMULATOR_MATCH_H