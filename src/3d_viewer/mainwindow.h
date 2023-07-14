#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#define GL_SILENCE_DEPRECATION

#include <QColorDialog>
#include <QCoreApplication>
#include <QDesktopServices>
#include <QFileDialog>
#include <QMainWindow>
#include <QMessageBox>
#include <QPainter>
#include <QSettings>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  void start_app();
  ~MainWindow();
 private slots:
  void openfileButton_clicked();
  void clearButton_clicked();
  void clearAllButton_clicked();
  void colorVertices_clicked();
  void colorLines_clicked();
  void colorBackground_clicked();
  void rotationValue_changed_X(double arg1);
  void rotationValue_changed_Y(double arg1);
  void rotationValue_changed_Z(double arg1);
  void translationValue_changed_X(double arg1);
  void translationValue_changed_Y(double arg1);
  void translationValue_changed_Z(double arg1);
  void scaleValue_changed(int value);
  void verticesType_activated(int index);
  void linesType_activated(int index);
  void sizeVertices_changed(int value);
  void sizeLines_changed(int value);
  void projectionType_activated(int index);
  void on_pushButton_screen_clicked();
  void on_pushButton_gif_clicked();
  void onQuit();

 private:
  Ui::MainWindow *ui;
};
#endif  // MAINWINDOW_H
