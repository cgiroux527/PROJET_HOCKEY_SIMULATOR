//
// Created by Utilisateur on 2026-04-24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved
#include "mainwindow.h"

#include <QPushButton>

#include "Equipe.h"
#include "Joueur.h"
#include "ui_MainWindow.h"



MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    afficherDonnees();

    ui->TitreSim->setEnabled(false);
    ui->TitreTableauCoachs->setEnabled(false);
    ui->TitreTableauJoueurs->setEnabled(false);

    connect(ui->BoutonPageSim, &QPushButton::clicked, this, [this]() {
        ui->MultiPageWidget->setCurrentIndex(1);
    });

    connect(ui->BoutonPageClassement, &QPushButton::clicked, this, [this]() {
        ui->MultiPageWidget->setCurrentIndex(0);
    });

}

void MainWindow::afficherDonnees() const {
    ui->TableauJoueurs->setRowCount(0);
    ui->TableauEntraineurs->setRowCount(0);

    ui->TableauJoueurs->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->TableauEntraineurs->setEditTriggers(QAbstractItemView::NoEditTriggers);

    Equipe equipeCharge;
    equipeCharge.charger("../equipe1.csv");

    int row = 0;

    int row2 = 0;
    for (auto personne : equipeCharge.getPersonnes()) {
        if (personne->getNumero() != 0) {
            ui->TableauJoueurs->insertRow(row);
            ui->TableauJoueurs->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(personne->getNom())));
            ui->TableauJoueurs->setItem(row, 1, new QTableWidgetItem(QString::number(personne->getNumero())));
            ui->TableauJoueurs->setItem(row, 2, new QTableWidgetItem(QString::fromStdString(personne->getPosition())));
            row++;
        } else {
            ui->TableauEntraineurs->insertRow(row2);
            ui->TableauEntraineurs->setItem(row2, 0, new QTableWidgetItem(QString::fromStdString(personne->getNom())));
            ui->TableauEntraineurs->setItem(row2, 1, new QTableWidgetItem(QString::fromStdString(personne->getPosition())));
            row2++;
        }
    }
}

MainWindow::~MainWindow() {
    delete ui;
}