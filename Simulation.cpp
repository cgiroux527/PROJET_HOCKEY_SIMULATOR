//
// Created by Utilisateur on 2026-04-29.
//

#include "Simulation.h"

const int NOMBRE_MATCH_SAISON = 82;

Simulation::Simulation() {
    for (size_t i = 0; i < NOMBRE_MATCH_SAISON; i++) {
        _calendrier.push(new Match())
    }
}
