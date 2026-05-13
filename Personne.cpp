//
// Created by Utilisateur on 2026-04-24.
//

#include "Personne.h"

Personne::Personne(const std::string& nom) {
    setNom(nom);
}

Personne::Personne() {
    setNom("");
}

const std::string& Personne::getNom() const{
    return _nom;
}

void Personne::setNom(const std::string& nom) {
    _nom = nom;
}

int Personne::getOVR() {
    return 0;
}
