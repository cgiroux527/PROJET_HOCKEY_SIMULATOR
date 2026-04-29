//
// Created by Utilisateur on 2026-04-28.
//

#include "Equipe.h"

#include <fstream>

Equipe::Equipe() {
    _parser = CSVParser(';',false);
}


void Equipe::charger(const std::string &nomFichier) {
    std::ifstream fichier;
    fichier.open(nomFichier);
    if (!fichier.is_open()) {
        std::cerr << "L'ouverture du fichier a échoué." << std::endl;
        return;
    }
    _parser.parse(fichier);

    _joueurs.clear();
    _entraineurs.clear();

    for (size_t i = 0; i < _parser.getNumRows(); i++) {
        if (_parser.getInt(i,1) != 0) {
            _joueurs.emplace_back(_parser.getInt(i,1),_parser.getString(i,2),_parser.getString(i,0));
        } else {
            _entraineurs.emplace_back(_parser.getString(i,2),_parser.getString(i,0));
        }
    }

    fichier.close();
}

std::vector<Entraineur> Equipe::getEntraineur() {
    return _entraineurs;
}

std::list<Joueur> Equipe::getJoueurs() {
    return _joueurs;
}

void Equipe::sauvegarder(const std::string &nomFichier) {
    std::ofstream fichier;
    fichier.open(nomFichier);
    if (!fichier.is_open()) {
        std::cerr << "L'ouverture du fichier a échoué." << std::endl;
        return;
    }
    for (auto it = _joueurs.begin(); it != _joueurs.end(); it++) {
        fichier << it->getNom() << ";" << it->getNumero() << ";" << it->getPosition() << '\n';
    }
    for (auto it = _entraineurs.begin(); it != _entraineurs.end(); it++) {
        fichier << it->getNom() << ";0;" << it->getPoste() << '\n';
    }
}

