//
// Created by Utilisateur on 2026-04-24.
//

#include "Joueur.h"

Joueur::Joueur(int numero, std::string position, std::string nom) {
    setNom(nom);
    setNumero(numero);
    setPosition(position);
}

void Joueur::afficher() {

}

void Joueur::setNumero(int numero) {
    _numero = numero;
}

void Joueur::setPosition(std::string &position) {
    _position = position;
}

