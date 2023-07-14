#include <QApplication>

#include "mainwindow.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  MainWindow w;
  w.setWindowTitle("3D Viewer v1.0");
  w.show();
  w.start_app();
  return a.exec();
}
