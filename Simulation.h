//
// Created by Utilisateur on 2026-04-29.
//

#ifndef PROJET_HOCKEY_SIMULATOR_SIMULATION_H
#define PROJET_HOCKEY_SIMULATOR_SIMULATION_H

#include <queue>
#include "Match.h"
#include "Equipe.h"
#include "ResultatMatch.h"

class Simulation {
private:
  std::queue<Match> _calendrier;

public:
  Simulation();

  ResultatMatch simulerMatch(const Equipe& equipeSimu);

  const std::queue<Match>& getCalendrier() const;
};


#endif //PROJET_HOCKEY_SIMULATOR_SIMULATION_H