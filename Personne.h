//
// Created by Utilisateur on 2026-04-24.
//

#include <iostream>

#ifndef PROJET_HOCKEY_SIMULATOR_PERSONNE_H
#define PROJET_HOCKEY_SIMULATOR_PERSONNE_H


class Personne {
private:
    std::string _nom;


public:
    Personne(std::string nom);

    virtual void afficher();

};


#endif //PROJET_HOCKEY_SIMULATOR_PERSONNE_H