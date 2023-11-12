#include <iostream>

#include "ui_view.h"
#include "view.h"

namespace awfl {
void View::LoadSettings_() {
  QString temp = QCoreApplication::applicationDirPath();
  auto pos = temp.indexOf("/build", 0);
  temp = temp.left(pos);
  QSettings settings(temp + "/settings.ini", QSettings::IniFormat);

  settings.beginGroup("Settings");

  ui_->openGLWidget->SetFileName(settings.value("filePath").toString());
  ReadFile_(ui_->openGLWidget->GetFileName());

  ui_->dSBox_Xr->setValue(settings.value("dSBox_Xr").toDouble());
  ui_->dSBox_Yr->setValue(settings.value("dSBox_Xr").toDouble());
  ui_->dSBox_Zr->setValue(settings.value("dSBox_Xr").toDouble());

  ui_->dSBox_Xt->setValue(settings.value("dSBox_Xt").toDouble());
  ui_->dSBox_Yt->setValue(settings.value("dSBox_Yt").toDouble());
  ui_->dSBox_Zt->setValue(settings.value("dSBox_Zt").toDouble());

  ui_->horizontalSlider_Scale->setValue(
      settings.value("horizontalSlider_Scale").toInt());
  ui_->horizontalSlider_V->setValue(
      settings.value("horizontalSlider_V").toInt());
  ui_->horizontalSlider_L->setValue(
      settings.value("horizontalSlider_L").toInt());

  ui_->openGLWidget->SetTypeVertex(
      (Type)settings.value("comboBox_V", 1).toInt());
  ui_->openGLWidget->SetTypeEdge((Type)settings.value("comboBox_L", 1).toInt());
  ui_->openGLWidget->SetProjection(
      (Projection)settings.value("comboBox_P").toInt());

  ui_->comboBox_P->setCurrentIndex(ui_->openGLWidget->GetProjection());
  ui_->comboBox_V->setCurrentIndex(ui_->openGLWidget->GetTypeVertex());
  ui_->comboBox_L->setCurrentIndex(ui_->openGLWidget->GetTypeEdge());

  ui_->openGLWidget->SetColorVertex(
      settings.value("colorVertices", QColor(Qt::white)).value<QColor>());
  ui_->openGLWidget->SetColorEdge(
      settings.value("colorLines", QColor(Qt::white)).value<QColor>());
  ui_->openGLWidget->SetColorBG(
      settings.value("colorBackground", QColor(Qt::black)).value<QColor>());

  settings.endGroup();

  ui_->openGLWidget->update();
}

void View::SaveSettings_() {
  QString temp = QCoreApplication::applicationDirPath();
  auto pos = temp.indexOf("/build", 0);
  temp = temp.left(pos);
  QSettings settings(temp + "/settings.ini", QSettings::IniFormat);

  settings.beginGroup("Settings");

  settings.setValue("filePath", ui_->openGLWidget->GetFileName());

  settings.setValue("dSBox_Xt", ui_->dSBox_Xt->value());
  settings.setValue("dSBox_Yt", ui_->dSBox_Yt->value());
  settings.setValue("dSBox_Zt", ui_->dSBox_Zt->value());

  settings.setValue("dSBox_Xr", ui_->dSBox_Xr->value());
  settings.setValue("dSBox_Yr", ui_->dSBox_Yr->value());
  settings.setValue("dSBox_Zr", ui_->dSBox_Zr->value());

  settings.setValue("horizontalSlider_Scale",
                    ui_->horizontalSlider_Scale->value());
  settings.setValue("horizontalSlider_V", ui_->horizontalSlider_V->value());
  settings.setValue("horizontalSlider_L", ui_->horizontalSlider_L->value());

  settings.setValue("colorVertices", ui_->openGLWidget->GetColorVertex());
  settings.setValue("colorLines", ui_->openGLWidget->GetColorEdge());
  settings.setValue("colorBackground", ui_->openGLWidget->GetColorBG());

  settings.setValue("comboBox_P", ui_->comboBox_P->currentIndex());
  settings.setValue("comboBox_V", ui_->comboBox_V->currentIndex());
  settings.setValue("comboBox_L", ui_->comboBox_L->currentIndex());

  settings.endGroup();
}
}  // namespace awfl
