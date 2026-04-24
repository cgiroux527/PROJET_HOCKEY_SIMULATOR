//
// Created by Utilisateur on 2026-04-24.
//


#ifndef PROJET_HOCKEY_SIMULATOR_PERSONNE_H
#define PROJET_HOCKEY_SIMULATOR_PERSONNE_H

#include "CSVParser.h"

class Personne {
private:
    std::string _nom;
    CSVParser _parser;

public:
    Personne(std::string nom);

    virtual void afficher();

};


#endif //PROJET_HOCKEY_SIMULATOR_PERSONNE_H