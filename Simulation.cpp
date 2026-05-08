//
// Created by Utilisateur on 2026-04-29.
//
#include <string>
#include <random>
#include "constantesSimu.h"
#include "Simulation.h"

Simulation::Simulation() {
    std::random_device aleatoire;
    std::mt19937 gen(aleatoire());
    std::uniform_int_distribution<> index(0, TAILLE - 1);

    for (size_t i = 0; i < NOMBRE_MATCH_SAISON; i++) {
        int indexEquipe = index(gen);
        _calendrier.push(Match(EQUIPES[indexEquipe], overallEquipes[indexEquipe]));
    }
}

ResultatMatch Simulation::simulerMatch(const std::list<Personne*>& roster) {
    std::random_device aleatoire;
    std::mt19937 gen(aleatoire());

    double overallAdverse = _calendrier.front().getOverall();

    double sommeLocal = 0;
    int nbJoueur = 0;
    for (auto it = roster.begin(); it != roster.end(); ++it) {
        if ((*it)->getNumero() != 0) {
            sommeLocal += (*it)->getOVR();
            nbJoueur++;
        }
        if (nbJoueur == 0) {
            throw std::out_of_range("le roster n'a aucun joueur");
        }
    }
    double overallLocal = sommeLocal/nbJoueur;
    std::discrete_distribution<> dist({overallAdverse, overallLocal});

    int gagnant = dist(gen);
    int scoreLocal = 0;
    int scoreAdverse = 0;

    double bonus = (std::abs(overallAdverse - overallLocal)) * MULTIPLICATEUR_BONNUS;
    std::uniform_real_distribution<> butsBase(1.0, 4.0);
    if (gagnant == 0) {
        scoreAdverse = butsBase(gen) + bonus;
        scoreLocal = std::uniform_int_distribution<>(0, scoreAdverse - 1)(gen);
    } else {
        scoreLocal = butsBase(gen) + bonus;
        scoreAdverse = std::uniform_int_distribution<>(0, scoreLocal - 1)(gen);
    }
    _calendrier.pop();
    return ResultatMatch(scoreLocal, scoreAdverse);
}

const std::queue<Match> &Simulation::getCalendrier() const {
    return _calendrier;
}


