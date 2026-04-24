//
// Created by Utilisateur on 2026-04-24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_App.h" resolved

#include "app.h"
#include "ui_App.h"


App::App(QWidget *parent) : QMainWindow(parent), ui(new Ui::App) {
    ui->setupUi(this);
}

App::~App() {
    delete ui;
}