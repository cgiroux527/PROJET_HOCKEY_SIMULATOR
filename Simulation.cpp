//
// Created by Utilisateur on 2026-04-29.
//
#include <string>
#include <ctime>
#include <algorithm>
#include <random>
#include "Simulation.h"

const int NOMBRE_MATCH_SAISON = 82;
const std::string EQUIPES[] = {"Boston Browns","New york Avenger", "Tampa Bay Thunder", "Ottawa Ministers"};
int overallEquipes[] = {1233,1,31,23};
const int TAILLE = 4;

Simulation::Simulation() {
    std::random_device aleatoire;
    std::mt19937 generateur(aleatoire());
    std::shuffle(overallEquipes, overallEquipes + TAILLE, generateur);

    for (size_t i = 0; i < NOMBRE_MATCH_SAISON; i++) {
        int indexAleatoire = std::rand() % TAILLE;
        _calendrier.push(Match(EQUIPES[indexAleatoire], overallEquipes[indexAleatoire]));
    }
}
