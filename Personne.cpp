//
// Created by Utilisateur on 2026-04-24.
//

#include "Personne.h"

Personne::Personne(std::string nom) {
    setNom(nom);
}

Personne::Personne() {
    setNom("");
}


void Personne::afficher() {

}

std::string Personne::getNom() {
    return _nom;
}

void Personne::setNom(std::string nom) {
    _nom = nom;
}


