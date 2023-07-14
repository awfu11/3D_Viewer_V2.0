#include "glview.h"

GLView::GLView(QWidget* parent) : QOpenGLWidget(parent) {
  rotation[0] = 0.0;
  rotation[1] = 0.0;
  rotation[2] = 0.0;

  translation[0] = 0.0;
  translation[1] = 0.0;
  translation[2] = 0.0;

  scale = 1.0;

  typeVertices = 1;
  typeLines = 1;

  sizeVertices = 1.0;
  sizeLines = 1.0;

  projection = 0;

  maxSizeAxis = 1;

  colorVertices.setRedF(1.0f);
  colorVertices.setGreenF(1.0f);
  colorVertices.setBlueF(1.0f);

  colorLines.setRedF(1.0f);
  colorLines.setGreenF(1.0f);
  colorLines.setBlueF(1.0f);

  colorBackground.setRedF(0.0f);
  colorBackground.setGreenF(0.0f);
  colorBackground.setBlueF(0.0f);
}

GLView::~GLView() { freeData(&model); }

void GLView::defineSize() {
  double maxSize = fabs(model.initialVertices[0]);
  for (int i = 0; i < model.numbersOfVertices; i++) {
    if (maxSize < fabs(model.initialVertices[i])) {
      maxSize = fabs(model.initialVertices[i]);
    }
  }
  maxSizeAxis = maxSize;
}

void GLView::openFile() {
  const char* fileName;
  QByteArray str = filePath.toLocal8Bit();
  fileName = str.constData();
  numV = 0;
  numL = 0;
  if (!filePath.isEmpty()) {
    freeData(&model);
    if (getNumbers(fileName, &model) == OK) {
      readOBJ(fileName, &model);
      numV = model.numbersOfVertices / 3;
      numL = model.numbersOfLines / 2;
      defineSize();
    }
  }
}

void GLView::initializeGL() {
  initializeOpenGLFunctions();
  glEnable(GL_DEPTH);
}

void GLView::settingProjection() {
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  if (projection == 1) {
    gluPerspective(90.0, sizeW / sizeH, 0.0001, 8 * maxSizeAxis);
  } else {
    glOrtho(-2 * maxSizeAxis, 2 * maxSizeAxis, -2 * maxSizeAxis,
            2 * maxSizeAxis, 0.0001, 8 * maxSizeAxis);
  }
  glTranslated(0.0, 0.0, -3 * maxSizeAxis);
}

void GLView::resizeGL(int width, int height) {
  sizeW = width;
  sizeH = height;
  glViewport(0, 0, height, width);
}

void GLView::paintGL() {
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glClearColor(colorBackground.redF(), colorBackground.greenF(),
               colorBackground.blueF(), 1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  settingProjection();
  if (!filePath.isEmpty()) {
    glEnableVertexAttribArray(0);
    glEnableClientState(GL_VERTEX_ARRAY);

    affineTransformation(&model, scale, translation, rotation);

    displayVertices();
    displayLines();

    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableVertexAttribArray(0);
  }
}

void GLView::displayVertices() {
  if (typeVertices == SMOOTH) {
    glDisable(GL_POINT_SPRITE);
    glEnable(GL_POINT_SMOOTH);
  } else if (typeVertices == SPRITE) {
    glDisable(GL_POINT_SMOOTH);
    glEnable(GL_POINT_SPRITE);
  }
  if (typeVertices != NONE) {
    glColor3f(colorVertices.redF(), colorVertices.greenF(),
              colorVertices.blueF());
    glPointSize(sizeVertices);
    glVertexPointer(3, GL_DOUBLE, 0, model.vertices);
    glDrawArrays(GL_POINTS, 0, model.numbersOfVertices / 3);
  }
}

void GLView::displayLines() {
  if (typeLines == DASHED) {
    glLineStipple(3, 0x00FF);
    glEnable(GL_LINE_STIPPLE);
  } else {
    glDisable(GL_LINE_STIPPLE);
  }
  if (typeLines != NONE) {
    glColor3f(colorLines.redF(), colorLines.greenF(), colorLines.blueF());
    glLineWidth(sizeLines);
    glDrawElements(GL_LINES, model.numbersOfLines, GL_UNSIGNED_INT,
                   model.lines);
  }
}

void GLView::mousePressEvent(QMouseEvent* mousePressed) {
  mousePosition = mousePressed->pos();
}

void GLView::mouseMoveEvent(QMouseEvent* mouseEvent) {
  rotation[1] +=
      5e-4 * 180 / M_PI * (mouseEvent->pos().x() - mousePosition.x());
  rotation[0] +=
      5e-4 * 180 / M_PI * (mouseEvent->pos().y() - mousePosition.y());
  mousePosition = mouseEvent->pos();
  update();
}
