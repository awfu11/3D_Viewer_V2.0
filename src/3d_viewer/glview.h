#ifndef GLVIEW_H
#define GLVIEW_H
#define GL_SILENCE_DEPRECATION

#include <glu.h>

#include <QMessageBox>
#include <QMouseEvent>
#include <QOpenGLFunctions>
#include <QOpenGLWidget>
#include <QWidget>

#define NONE 0
#define SMOOTH 1
#define SPRITE 2

#define DASHED 2

extern "C" {
#include "3d_viewer.h"
}

class GLView : public QOpenGLWidget, protected QOpenGLFunctions {
 public:
  GLView(QWidget *parent);
  ~GLView();

  void openFile();

  QString filePath;
  int numV;
  int numL;

  int sizeH = 0;
  int sizeW = 0;

  double translation[3];
  double rotation[3];
  double scale;

  int typeVertices;
  int typeLines;

  int sizeVertices;
  int sizeLines;

  int projection;

  double maxSizeAxis;

  QColor colorVertices;
  QColor colorLines;
  QColor colorBackground;

 private:
  dataModel model;
  void displayVertices();
  void displayLines();
  void defineSize();
  void settingProjection();

  void initializeGL() override;
  void resizeGL(int width, int height) override;
  void paintGL() override;

  QPoint mousePosition;
  void mouseMoveEvent(QMouseEvent *) override;
  void mousePressEvent(QMouseEvent *) override;
};

#endif  // GLVIEW_H
