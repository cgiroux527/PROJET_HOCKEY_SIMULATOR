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

    _personnes.clear();

    for (size_t i = 0; i < _parser.getNumRows(); i++) {
        if (_parser.getInt(i,1) != 0) {
            _personnes.push_back(new Joueur(_parser.getInt(i,1),_parser.getString(i,2),_parser.getString(i,0),_parser.getInt(i,3)));
        } else {
            _personnes.push_back(new Entraineur(_parser.getString(i,2),_parser.getString(i,0)));
        }
    }

    fichier.close();
}


void Equipe::sauvegarder(const std::string &nomFichier) {
    std::ofstream fichier;
    fichier.open(nomFichier);
    if (!fichier.is_open()) {
        std::cerr << "L'ouverture du fichier a échoué." << std::endl;
        return;
    }
    //  TODO ECRIRE DANS LE FICHIER LES DONNEES DE LA SIMULATION

    fichier.close();
}

void Equipe::ajouterAlignement() {
    std::vector<Joueur> ligne;
    for (auto personne : _personnes) {
        if (personne->getNumero() != 0) {
            if (personne->getPosition() != "D" && personne->getPosition() != "G") {
                Joueur* j = dynamic_cast<Joueur*>(personne);
                ligne.push_back(*j);
                if (ligne.size() == TAILLE_LIGNE_ATTAQUE) {
                    _alignementAttaque.push_back(ligne);
                    ligne.clear();
                }
            } else if (personne->getPosition() == "D") {
                Joueur* j = dynamic_cast<Joueur*>(personne);
                ligne.push_back(*j);
                if (ligne.size() == TAILLE_LIGNE_DEFENSE) {
                    _alignementDefense.push_back(ligne);
                    ligne.clear();
                }
            } else {
                Joueur* j = dynamic_cast<Joueur*>(personne);
                _gardiens.push_back(*j);
            }
        }
    }
}

const std::list<Personne*>& Equipe::getPersonnes() const {
    return _personnes;
}

