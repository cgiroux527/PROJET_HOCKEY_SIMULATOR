//
// Created by Utilisateur on 2026-04-24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "mainwindow.h"
#include "ui_MainWindow.h"
#include <iostream>


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::boutonClique);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::boutonClique() {
    std::cout << "ok";
}
