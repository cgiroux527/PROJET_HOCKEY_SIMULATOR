//
// Created by Utilisateur on 2026-04-24.
//

#include "Entraineur.h"

Entraineur::Entraineur(std::string poste, std::string nom) {
    setPoste(poste);
    setNom(nom);
}

void Entraineur::setPoste(const std::string &poste) {
    _poste = poste;
}

void Entraineur::afficher() {

}

const std::string &Entraineur::getPosition() {
    return _poste;
}

int Entraineur::getNumero() {
    return 0;
}
