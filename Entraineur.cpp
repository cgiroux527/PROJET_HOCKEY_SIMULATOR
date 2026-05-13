//
// Created by Utilisateur on 2026-04-24.
//

#include "Entraineur.h"

Entraineur::Entraineur(const std::string &poste,const std::string &nom) {
    setPoste(poste);
    setNom(nom);
}

void Entraineur::setPoste(const std::string &poste) {
    _poste = poste;
}

void Entraineur::afficher(QTableWidget *tableJoueurs, QTableWidget *tableEntraineurs, int &rowJoueurs, int &rowEntraineurs) {
    tableEntraineurs->insertRow(rowEntraineurs);
    tableEntraineurs->setItem(rowEntraineurs, 0, new QTableWidgetItem(QString::fromStdString(getNom())));
    tableEntraineurs->setItem(rowEntraineurs, 1, new QTableWidgetItem(QString::fromStdString(getPosition())));
    rowEntraineurs++;
}

const std::string &Entraineur::getPosition() {
    return _poste;
}

int Entraineur::getNumero() {
    return 0;
}
