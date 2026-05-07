//
// Created by Utilisateur on 2026-04-24.
//

#ifndef PROJET_HOCKEY_SIMULATOR_MAINWINDOW_H
#define PROJET_HOCKEY_SIMULATOR_MAINWINDOW_H

#include <QMainWindow>
#include "Joueur.h"
#include "Equipe.h"
#include <vector>


QT_BEGIN_NAMESPACE

namespace Ui {
    class MainWindow;
}

QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT
private:
    Equipe _equipe;

    std::vector<Joueur*> _joueurs;
    std::vector<Joueur*> _lineup;
    std::vector<Joueur*> _disponibles;

    Joueur* _joueurActif = nullptr;
    std::string _positionSelectionnee;

    void chargerJoueursDepuisEquipe();
    void initialiserLineup();
    void afficherRemplacements(const std::string& position);
    Joueur* trouverJoueur(const std::string& texte);
    void enleverDisponible(Joueur* j);
    void rafraichirUI();
    Ui::MainWindow *ui;

public:
    explicit MainWindow(QWidget *parent = nullptr);

    void afficherDonnees() const;


    ~MainWindow() override;
};


#endif //PROJET_HOCKEY_SIMULATOR_MAINWINDOW_H