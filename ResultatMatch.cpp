//
// Created by Utilisateur on 2026-05-08.
//

#include "ResultatMatch.h"

ResultatMatch::ResultatMatch(int scoreLocal, int scoreAdverse) {
    _scoreAdverse = scoreAdverse;
    _scoreLocal = scoreLocal;
}

bool ResultatMatch::getGagnant() const {
    if (_scoreLocal > _scoreAdverse) {
        return true;
    }
    return false;
}

int ResultatMatch::getScoreAdverse() const {
    return _scoreAdverse;
}

int ResultatMatch::getScoreLocal() const {
    return _scoreLocal;
}

