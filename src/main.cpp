#include <QApplication>
#include <QPushButton>
#include "MainApp.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    auto *app = new MainApp;
    app->resize(800, 600);
    app->show();
    return QApplication::exec();
}
