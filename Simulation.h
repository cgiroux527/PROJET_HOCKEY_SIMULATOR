//
// Created by Utilisateur on 2026-04-29.
//

#ifndef PROJET_HOCKEY_SIMULATOR_SIMULATION_H
#define PROJET_HOCKEY_SIMULATOR_SIMULATION_H

#include <queue>
#include "Match.h"

class Simulation {
private:
  std::queue<Match*> _calendrier;

public:
  Simulation();

};


#endif //PROJET_HOCKEY_SIMULATOR_SIMULATION_H