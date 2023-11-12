#include <QApplication>

#include "View/view.h"

int main(int argc, char *argv[]) {
  using namespace awfl;
  QApplication a(argc, argv);

  Model model;
  Controller controller(&model);
  View view(&controller);

  view.show();
  return a.exec();
}
