//
// Created by Utilisateur on 2026-05-08.
//

#ifndef PROJET_HOCKEY_SIMULATOR_RESULTATMATCH_H
#define PROJET_HOCKEY_SIMULATOR_RESULTATMATCH_H


class ResultatMatch {
private:
    int _scoreLocal;
    int _scoreAdverse;

public:
    ResultatMatch(int scoreLocal, int scoreAdverse);

    bool getGagnant() const;
    int getScoreLocal() const;
    int getScoreAdverse() const;
};


#endif //PROJET_HOCKEY_SIMULATOR_RESULTATMATCH_H