#ifndef VIEWER_SRC_VIEW_VIEW_H_
#define VIEWER_SRC_VIEW_VIEW_H_
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
#include <QTimer>

#include "../Controller/controller.h"
#include "QtGifImage/gifimage/qgifimage.h"
#include "glview.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class View;
}
QT_END_NAMESPACE

namespace awfl {

class View : public QMainWindow {
  Q_OBJECT

 public:
  View(Controller* cont, QWidget* parent = nullptr);
  ~View();

 private slots:
  void RotationValueChangedX_(double arg1);
  void RotationValueChangedY_(double arg1);
  void RotationValueChangedZ_(double arg1);

  void TranslationValueChangedX_(double arg1);
  void TranslationValueChangedY_(double arg1);
  void TranslationValueChangedZ_(double arg1);

  void ScaleValueChanged_(int value);

  void VerticesTypeActivated_(int index);
  void LinesTypeActivated_(int index);

  void SizeVerticesChanged_(int value);
  void SizeLinesChanged_(int value);

  void ProjectionTypeActivated_(int index);

  void ClearButtonClicked_();
  void ClearAllButtonClicked_();

  void OpenfileButtonClicked_();

  void ColorVerticesClicked_();
  void ColorLinesClicked_();
  void ColorBackgroundClicked_();

  void ScreenButtonClicked_();
  void GifButtonClicked_();

  void GifCreate_();
  void GifTimer_();

 private:
  Ui::View* ui_;
  Controller* controller_;

  int frame_ = 0;
  QTimer* timer_;
  QGifImage* gifIm_;
  QString gifFileName_;

  void ReadFile_(QString filePath);

  void SaveSettings_();
  void LoadSettings_();

  QImage GetImage_();
  QString GetDir_() const;
};

}  // namespace awfl

#endif  // VIEWER_SRC_VIEW_VIEW_H_
