#ifndef VIEWER_SRC_VIEW_GLVIEW_H_
#define VIEWER_SRC_VIEW_GLVIEW_H_
#define GL_SILENCE_DEPRECATION

#include <glu.h>

#include <QMessageBox>
#include <QMouseEvent>
#include <QOpenGLFunctions>
#include <QOpenGLWidget>
#include <QWidget>

#include "../Controller/controller.h"

namespace awfl {
enum Type { NONE = 0, SMOOTH = 1, SPRITE = 2, SOLID = 1, DASHED = 2 };

enum Projection { CENTRAL, PARALLEL };

class GLView : public QOpenGLWidget, protected QOpenGLFunctions {
 public:
  GLView(QWidget *parent);
  ~GLView();

  void SetParamAx(double angle) { param_.angleX = angle; }
  void SetParamAy(double angle) { param_.angleY = angle; }
  void SetParamAz(double angle) { param_.angleZ = angle; }

  void SetParamTx(double offset) { param_.offsetX = offset; }
  void SetParamTy(double offset) { param_.offsetY = offset; }
  void SetParamTz(double offset) { param_.offsetZ = offset; }

  void SetParamScale(double scale) { param_.scale = scale; }
  double GetParamScale() const { return param_.scale; }

  QString GetFileName() const { return fileName_; }
  void SetFileName(const QString &file) { fileName_ = file; }

  Projection GetProjection() const { return projection_; }
  void SetProjection(Projection projection) { projection_ = projection; }

  Type GetTypeVertex() const { return typeVertex_; }
  void SetTypeVertex(Type type) { typeVertex_ = type; }
  QColor &GetColorVertex() { return colorVertex_; }
  void SetColorVertex(QColor color) { colorVertex_ = color; }
  int GetSizeVertex() const { return sizeVertex_; }
  void SetSizeVertex(int size) { sizeVertex_ = size; }

  Type GetTypeEdge() const { return typeEdge_; }
  void SetTypeEdge(Type type) { typeEdge_ = type; }
  QColor &GetColorEdge() { return colorEdge_; }
  void SetColorEdge(QColor color) { colorEdge_ = color; }
  int GetSizeEdge() const { return sizeEdge_; }
  void SetSizeEdge(int size) { sizeEdge_ = size; }

  QColor &GetColorBG() { return colorBackground_; }
  void SetColorBG(QColor color) { colorBackground_ = color; }

  void SetController(Controller *cont) { controller_ = cont; }

  void OpenFile(QString file);

 private:
  Controller *controller_;

  Params param_;

  int sizeH_ = 0, sizeW_ = 0;
  double maxSizeAxis_ = 1.0;

  QString fileName_;

  Projection projection_ = CENTRAL;

  Type typeVertex_ = SMOOTH;
  QColor colorVertex_;
  int sizeVertex_ = 1;

  Type typeEdge_ = SOLID;
  QColor colorEdge_;
  int sizeEdge_ = 1;

  QColor colorBackground_;

  void DisplayVertices_();
  void DisplayEdges_();
  void SettingProjection_();

  void initializeGL() override;
  void resizeGL(int width, int height) override;
  void paintGL() override;

  QPoint mousePosition_;
  void mouseMoveEvent(QMouseEvent *) override;
  void mousePressEvent(QMouseEvent *) override;
  void wheelEvent(QWheelEvent *event) override;
};

}  // namespace awfl

using namespace awfl;

#endif  // VIEWER_SRC_VIEW_GLVIEW_H_
