//
// Created by Utilisateur on 2026-04-24.
//

#ifndef PROJET_HOCKEY_SIMULATOR_MAINWINDOW_H
#define PROJET_HOCKEY_SIMULATOR_MAINWINDOW_H

#include <QMainWindow>


QT_BEGIN_NAMESPACE

namespace Ui {
    class MainWindow;
}

QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    void afficherDonnees();

    ~MainWindow() override;

private:

    Ui::MainWindow *ui;
};


#endif //PROJET_HOCKEY_SIMULATOR_MAINWINDOW_H