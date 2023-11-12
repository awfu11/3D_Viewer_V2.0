#include "glview.h"

namespace awfl {
GLView::GLView(QWidget* parent) : QOpenGLWidget(parent) {
  param_ = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0};

  colorVertex_.setRgbF(1.0f, 1.0f, 1.0f);
  colorEdge_.setRgbF(1.0f, 1.0f, 1.0f);
  colorBackground_.setRgbF(0.0f, 0.0f, 0.0f);
}

GLView::~GLView() {}

void GLView::OpenFile(QString file) {
  fileName_ = file;
  if (!fileName_.isEmpty()) {
    std::string path = fileName_.toStdString();
    controller_->ReadData(path);
    maxSizeAxis_ = controller_->Normalization();
  }
}

void GLView::initializeGL() {
  initializeOpenGLFunctions();
  glEnable(GL_DEPTH);
}

void GLView::resizeGL(int width, int height) {
  sizeW_ = width, sizeH_ = height;
  glViewport(0, 0, height, width);
}

void GLView::paintGL() {
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  glClearColor(colorBackground_.redF(), colorBackground_.greenF(),
               colorBackground_.blueF(), 1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  SettingProjection_();

  glEnableVertexAttribArray(0);
  glEnableClientState(GL_VERTEX_ARRAY);

  controller_->Transform(param_);
  DisplayVertices_();
  DisplayEdges_();

  glDisableClientState(GL_VERTEX_ARRAY);
  glDisableVertexAttribArray(0);
}

void GLView::DisplayVertices_() {
  if (typeVertex_ == SMOOTH) {
    glDisable(GL_POINT_SPRITE);
    glEnable(GL_POINT_SMOOTH);
  } else if (typeVertex_ == SPRITE) {
    glDisable(GL_POINT_SMOOTH);
    glEnable(GL_POINT_SPRITE);
  }
  if (typeVertex_ != NONE) {
    glColor3f(colorVertex_.redF(), colorVertex_.greenF(), colorVertex_.blueF());
    glPointSize(sizeVertex_);
    glVertexPointer(3, GL_DOUBLE, 0, controller_->GetVertices());
    glDrawArrays(GL_POINTS, 0, controller_->GetVerticesNumbers() / 3);
  }
}

void GLView::DisplayEdges_() {
  if (typeEdge_ == DASHED) {
    glLineStipple(3, 0x00FF);
    glEnable(GL_LINE_STIPPLE);
  } else {
    glDisable(GL_LINE_STIPPLE);
  }
  if (typeEdge_ != NONE) {
    glColor3f(colorEdge_.redF(), colorEdge_.greenF(), colorEdge_.blueF());
    glLineWidth(sizeEdge_);
    glDrawElements(GL_LINES, controller_->GetEdgesNumbers(), GL_UNSIGNED_INT,
                   controller_->GetEdges());
  }
}

void GLView::SettingProjection_() {
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  if (projection_ == PARALLEL) {
    gluPerspective(90.0, sizeW_ / sizeH_, 0.0001, 12 * maxSizeAxis_);
  } else {
    glOrtho(-3 * maxSizeAxis_, 3 * maxSizeAxis_, -3 * maxSizeAxis_,
            3 * maxSizeAxis_, 0.0001, 12 * maxSizeAxis_);
  }
  glTranslated(0.0, 0.0, -4 * maxSizeAxis_);
}

void GLView::mousePressEvent(QMouseEvent* mousePressed) {
  mousePosition_ = mousePressed->pos();
}

void GLView::mouseMoveEvent(QMouseEvent* mouseEvent) {
  param_.angleY +=
      1e-4 * 180 / M_PI * (mouseEvent->pos().x() - mousePosition_.x());
  param_.angleX +=
      1e-4 * 180 / M_PI * (mouseEvent->pos().y() - mousePosition_.y());
  mousePosition_ = mouseEvent->pos();
  update();
}

void GLView::wheelEvent(QWheelEvent* wheelEvent) {
  if (wheelEvent->angleDelta().y() > 0) {
    param_.offsetZ += maxSizeAxis_ / 10;
  } else if (wheelEvent->angleDelta().y() < 0) {
    param_.offsetZ -= maxSizeAxis_ / 10;
  }
  update();
}
}  // namespace awfl
