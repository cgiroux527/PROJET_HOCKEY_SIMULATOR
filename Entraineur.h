//
// Created by Utilisateur on 2026-04-24.
//

#ifndef PROJET_HOCKEY_SIMULATOR_ENTRAINEUR_H
#define PROJET_HOCKEY_SIMULATOR_ENTRAINEUR_H

#include <string>

#include "Personne.h"

class Entraineur : public Personne {
public :
    std::string _poste;
private:
    Entraineur(std::string poste);

    void afficher() override;

};


#endif //PROJET_HOCKEY_SIMULATOR_ENTRAINEUR_H