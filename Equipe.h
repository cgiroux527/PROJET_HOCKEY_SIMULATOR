//
// Created by Utilisateur on 2026-04-28.
//

#ifndef PROJET_HOCKEY_SIMULATOR_EQUIPE_H
#define PROJET_HOCKEY_SIMULATOR_EQUIPE_H
#include <list>

#include "CSVParser.h"
#include "Entraineur.h"
#include "Joueur.h"


class Equipe {
private:
    std::list<Personne*> _personnes;

    std::vector<std::vector<Joueur>> _alignementAttaque;
    std::vector<std::vector<Joueur>> _alignementDefense;
    std::vector<Joueur> _gardiens;

    CSVParser _parser;

public:
    Equipe();

    void ajouterAlignement();
    void ajouterGardien();
    void modifierAlignement(Joueur* joueur1, Joueur* joueur2);

    const std::list<Personne*>& getPersonnes() const;
    int getOverall() const;

    void charger(const std::string& nomFichier);
    void sauvegarder(const std::string& nomFichier);
};


#endif //PROJET_HOCKEY_SIMULATOR_EQUIPE_H