//
// Created by Utilisateur on 2026-04-24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved
#include <iostream>
#include "mainwindow.h"
#include "ui_MainWindow.h"

#include "cmake-build-debug/PROJET_HOCKEY_SIMULATOR_autogen/include/ui_MainWindow.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

}

MainWindow::~MainWindow() {
    delete ui;
}

