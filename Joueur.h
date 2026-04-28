//
// Created by Utilisateur on 2026-04-24.
//

#ifndef PROJET_HOCKEY_SIMULATOR_JOUEUR_H
#define PROJET_HOCKEY_SIMULATOR_JOUEUR_H

#include "Personne.h"

class Joueur : Personne{
private:
    int _numero;
    std::string _position;

public:
    Joueur(int numero,std::string position);

    void afficher() override;
};


#endif //PROJET_HOCKEY_SIMULATOR_JOUEUR_H