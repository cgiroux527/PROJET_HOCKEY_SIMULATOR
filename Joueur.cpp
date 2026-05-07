//
// Created by Utilisateur on 2026-04-24.
//

#include "Joueur.h"

Joueur::Joueur(int numero, std::string position, std::string nom, int ovr) {
    setNom(nom);
    setNumero(numero);
    setPosition(position);
    setOVR(ovr);
}

void Joueur::afficher() {

}

void Joueur::setNumero(int numero) {
    _numero = numero;
}

void Joueur::setPosition(const std::string &position) {
    _position = position;
}

int Joueur::getNumero() {
    return _numero;
}

const std::string& Joueur::getPosition() {
    return _position;
}

void Joueur::setOVR(int ovr) {
    _ovr = ovr;
}

int Joueur::getOVR() {
    return _ovr;
}