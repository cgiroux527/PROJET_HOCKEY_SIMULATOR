//
// Created by Utilisateur on 2026-04-24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved
#include <iostream>
#include "mainwindow.h"

#include "Equipe.h"
#include "Joueur.h"
#include "ui_MainWindow.h"

#include "cmake-build-debug/PROJET_HOCKEY_SIMULATOR_autogen/include/ui_MainWindow.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    ui->TableauJoueurs->setRowCount(0);

    Equipe equipeCharge;
    equipeCharge.charger("../equipe1.csv");

    int row = 0;
    for (auto it = equipeCharge.getJoueurs().begin(); it != equipeCharge.getJoueurs().end(); it++) {
        ui->TableauJoueurs->insertRow(row);
        ui->TableauJoueurs->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(it->getNom())));
        ui->TableauJoueurs->setItem(row, 1, new QTableWidgetItem(it->getNumero()));
        ui->TableauJoueurs->setItem(row, 2, new QTableWidgetItem(QString::fromStdString(it->getPosition())));
    }
}

MainWindow::~MainWindow() {
    delete ui;
}


