//
// Created by Utilisateur on 2026-04-24.
//


#ifndef PROJET_HOCKEY_SIMULATOR_PERSONNE_H
#define PROJET_HOCKEY_SIMULATOR_PERSONNE_H

#include "CSVParser.h"
#include <QTableWidget>

class Personne {
protected:
    std::string _nom;


public:
    virtual ~Personne() = default;

    Personne(const std::string& nom);

    Personne();

    const std::string& getNom() const;
    void setNom(const std::string& nom);

    virtual int getNumero() = 0;
    virtual const std::string& getPosition() = 0;

    virtual int getOVR();

    virtual void afficher(QTableWidget* tableJoueurs, QTableWidget* tableEntraineurs, int& rowJoueurs, int& rowEntraineurs) = 0;

};


#endif //PROJET_HOCKEY_SIMULATOR_PERSONNE_H