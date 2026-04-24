//
// Created by Utilisateur on 2026-04-24.
//

#ifndef PROJET_HOCKEY_SIMULATOR_APP_H
#define PROJET_HOCKEY_SIMULATOR_APP_H

#include <QMainWindow>


QT_BEGIN_NAMESPACE

namespace Ui {
    class App;
}

QT_END_NAMESPACE

class App : public QMainWindow {
    Q_OBJECT

public:
    explicit App(QWidget *parent = nullptr);

    ~App() override;

private:
    Ui::App *ui;
};


#endif //PROJET_HOCKEY_SIMULATOR_APP_H