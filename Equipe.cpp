//
// Created by Utilisateur on 2026-04-28.
//

#include "Equipe.h"

#include <fstream>

Equipe::Equipe() {
    _parser = CSVParser(';',false);
}


void Equipe::charger(std::string &nomFichier) {
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
            _joueurs.emplace_back(_parser.getInt(i,1),_parser.getString(i,2),_parser.getString(i,3));
        } else {
            _entraineurs.emplace_back(_parser.getString(i,2),_parser.getString(i,0));
        }
    }

    fichier.close();
}
