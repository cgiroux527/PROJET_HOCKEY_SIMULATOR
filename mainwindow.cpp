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
    //afficherDonnees();

    ui->TitreSim->setEnabled(false);
    connect(ui->BoutonPageSim, &QPushButton::clicked, this, [this]() {
    ui->MultiPageWidget->setCurrentIndex(0);
    });

}

void MainWindow::afficherDonnees() {
    ui->TableauJoueurs->setRowCount(0);
    ui->TableauEntraineurs->setRowCount(0);

    ui->TableauJoueurs->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->TableauEntraineurs->setEditTriggers(QAbstractItemView::NoEditTriggers);

    Equipe equipeCharge;
    equipeCharge.charger("../equipe1.csv");

    int row = 0;
    for (auto it = equipeCharge.getJoueurs().begin(); it != equipeCharge.getJoueurs().end(); it++) {
        ui->TableauJoueurs->insertRow(row);
        ui->TableauJoueurs->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(it->getNom())));
        ui->TableauJoueurs->setItem(row, 1, new QTableWidgetItem(QString::number(it->getNumero())));
        ui->TableauJoueurs->setItem(row, 2, new QTableWidgetItem(QString::fromStdString(it->getPosition())));
        row++;
    }

    int row2 = 0;
    for (auto it = equipeCharge.getEntraineur().begin(); it != equipeCharge.getEntraineur().end(); it++) {
        ui->TableauEntraineurs->insertRow(row2);
        ui->TableauEntraineurs->setItem(row2, 0, new QTableWidgetItem(QString::fromStdString(it->getNom())));
        ui->TableauEntraineurs->setItem(row2, 1, new QTableWidgetItem(QString::fromStdString(it->getPoste())));
        row2++;
    }
}

MainWindow::~MainWindow() {
    delete ui;
}