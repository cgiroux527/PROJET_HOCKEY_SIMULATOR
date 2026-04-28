//
// Created by Utilisateur on 2026-04-24.
//

#include "Entraineur.h"

Entraineur::Entraineur(std::string poste, std::string nom) {
    setPoste(poste);
    setNom(nom);
}

void Entraineur::setPoste(std::string &poste) {
    _poste = poste;
}


void Entraineur::afficher() {

}
