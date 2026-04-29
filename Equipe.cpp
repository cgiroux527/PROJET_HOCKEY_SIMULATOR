//
// Created by Utilisateur on 2026-04-28.
//

#include "Equipe.h"

#include <fstream>

const int TAILLE_LIGNE_ATTAQUE = 3;
const int TAILLE_LIGNE_DEFENSE = 2;

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
    for (size_t i = 0; i < _entraineurs.size(); i++) {
        fichier << _entraineurs[i].getNom() << ";0;" << _entraineurs[i].getPoste() << '\n';
    }
    fichier.close();
}

void Equipe::ajouterAlignement() {
    std::vector<Joueur> ligne;
    for (auto it = _joueurs.begin(); it != _joueurs.end(); it++) {
        if (it->getPosition() != "D" || it->getPosition() != "G") {
            ligne.push_back(*it);
            if (ligne.size() == TAILLE_LIGNE_ATTAQUE) {
                _alignementAttaque.push_back(ligne);
                ligne.clear();
            }
        } else if (it->getPosition() == "D") {
            ligne.push_back(*it);
            if (ligne.size() == TAILLE_LIGNE_DEFENSE) {
                _alignementDefense.push_back(ligne);
                ligne.clear();
            }
        } else {
            _gardiens.push_back(*it);
        }
    }
}



