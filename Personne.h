//
// Created by Utilisateur on 2026-04-24.
//


#ifndef PROJET_HOCKEY_SIMULATOR_PERSONNE_H
#define PROJET_HOCKEY_SIMULATOR_PERSONNE_H

#include "CSVParser.h"

class Personne {
protected:
    std::string _nom;

public:
    Personne(std::string nom);

    Personne();

    const std::string& getNom();
    void setNom(const std::string& nom);
    virtual void afficher() = 0;

};


#endif //PROJET_HOCKEY_SIMULATOR_PERSONNE_H