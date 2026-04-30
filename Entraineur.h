//
// Created by Utilisateur on 2026-04-24.
//

#ifndef PROJET_HOCKEY_SIMULATOR_ENTRAINEUR_H
#define PROJET_HOCKEY_SIMULATOR_ENTRAINEUR_H

#include <string>

#include "Personne.h"

class Entraineur : public Personne {
private :
    std::string _poste;
public :
    Entraineur(std::string poste, std::string nom);

    void setPoste(const std::string& poste);

    const std::string& getPoste();

    void afficher() override;

};


#endif //PROJET_HOCKEY_SIMULATOR_ENTRAINEUR_H