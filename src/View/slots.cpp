#include "ui_view.h"
#include "view.h"

namespace awfl {
void View::TranslationValueChangedX_(double arg1) {
  ui_->openGLWidget->SetParamTx(arg1);
  ui_->openGLWidget->update();
}

void View::TranslationValueChangedY_(double arg1) {
  ui_->openGLWidget->SetParamTy(arg1);
  ui_->openGLWidget->update();
}

void View::TranslationValueChangedZ_(double arg1) {
  ui_->openGLWidget->SetParamTz(arg1);
  ui_->openGLWidget->update();
}

void View::RotationValueChangedX_(double arg1) {
  ui_->openGLWidget->SetParamAx(arg1 / 180.0 * M_PI);
  ui_->openGLWidget->update();
}

void View::RotationValueChangedY_(double arg1) {
  ui_->openGLWidget->SetParamAy(arg1 / 180.0 * M_PI);
  ui_->openGLWidget->update();
}

void View::RotationValueChangedZ_(double arg1) {
  ui_->openGLWidget->SetParamAz(arg1 / 180.0 * M_PI);
  ui_->openGLWidget->update();
}

void View::ScaleValueChanged_(int value) {
  if (ui_->openGLWidget->GetParamScale() != value) {
    ui_->openGLWidget->SetParamScale(value);
  }
  ui_->openGLWidget->update();
}

void View::VerticesTypeActivated_(int index) {
  ui_->openGLWidget->SetTypeVertex((Type)index);
  ui_->openGLWidget->update();
}

void View::SizeVerticesChanged_(int value) {
  ui_->openGLWidget->SetSizeVertex(value);
  ui_->openGLWidget->update();
}

void View::LinesTypeActivated_(int index) {
  ui_->openGLWidget->SetTypeEdge((Type)index);
  ui_->openGLWidget->update();
}

void View::SizeLinesChanged_(int value) {
  ui_->openGLWidget->SetSizeEdge(value);
  ui_->openGLWidget->update();
}

void View::ProjectionTypeActivated_(int index) {
  ui_->openGLWidget->SetProjection((Projection)index);
  ui_->openGLWidget->update();
}

void View::ColorVerticesClicked_() {
  QColor colour = QColorDialog::getColor(Qt::white, this, "Select color:");
  ui_->openGLWidget->SetColorVertex(colour);
  ui_->openGLWidget->update();
}

void View::ColorLinesClicked_() {
  QColor colour = QColorDialog::getColor(Qt::white, this, "Select color:");
  ui_->openGLWidget->SetColorEdge(colour);
  ui_->openGLWidget->update();
}

void View::ColorBackgroundClicked_() {
  QColor colour = QColorDialog::getColor(Qt::white, this, "Select color:");
  ui_->openGLWidget->SetColorBG(colour);
  ui_->openGLWidget->update();
}

void View::ClearButtonClicked_() {
  ui_->dSBox_Xr->setValue(0.0);
  ui_->dSBox_Yr->setValue(0.0);
  ui_->dSBox_Zr->setValue(0.0);

  ui_->dSBox_Xt->setValue(0.0);
  ui_->dSBox_Yt->setValue(0.0);
  ui_->dSBox_Zt->setValue(0.0);

  ui_->horizontalSlider_Scale->setValue(1);

  ui_->horizontalSlider_V->setValue(1);
  ui_->comboBox_V->setCurrentIndex(1);
  VerticesTypeActivated_(1);

  ui_->horizontalSlider_L->setValue(1);
  ui_->comboBox_L->setCurrentIndex(1);
  LinesTypeActivated_(1);

  ui_->comboBox_P->setCurrentIndex(0);
  ProjectionTypeActivated_(0);

  ui_->openGLWidget->update();
}

void View::ClearAllButtonClicked_() {
  ClearButtonClicked_();
  ui_->openGLWidget->SetFileName("");
  ui_->openGLWidget->GetColorVertex().setRgbF(1.0f, 1.0f, 1.0f);
  ui_->openGLWidget->GetColorEdge().setRgbF(1.0f, 1.0f, 1.0f);
  ui_->openGLWidget->GetColorBG().setRgbF(0.0f, 0.0f, 0.0f);

  ui_->label_filename->setText("•File name: ");
  ui_->label_numV->setText("•Number of vertices: ");
  ui_->label_numL->setText("•Number of edges: ");

  controller_->ClearData();
  ui_->openGLWidget->update();
}
}  // namespace awfl
