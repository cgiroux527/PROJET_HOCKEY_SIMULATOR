#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include "mainwindow.h"
#include "Equipe.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    MainWindow window;
    window.show();

    return QApplication::exec();
}