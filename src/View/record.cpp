#include "ui_view.h"
#include "view.h"

namespace awfl {
QImage View::GetImage_() {
  QImage img(ui_->openGLWidget->size(), QImage::Format_RGB32);
  QPainter painter(&img);
  ui_->openGLWidget->render(&painter);
  return img;
}

void View::ScreenButtonClicked_() {
  QString fileName =
      QFileDialog::getSaveFileName(this, tr("Save file"), GetDir_() + "/images",
                                   tr("JPG (*.jpg);; BMP (*.bmp)"));
  QImage img = GetImage_();
  if (img.save(fileName)) {
    QMessageBox msgBox;
    msgBox.setText("Screenshot saved successfully.");
    msgBox.exec();
  } else {
    QMessageBox::warning(this, "", "Failed to save screenshot.");
  }
}

void View::GifTimer_() {
  timer_->setInterval(100);
  timer_->start();
}

void View::GifCreate_() {
  gifIm_->addFrame(GetImage_());
  if (frame_ == 50) {
    timer_->stop();
    gifIm_->save(gifFileName_);
    frame_ = 0;
    delete gifIm_;
    QMessageBox msgBox;
    msgBox.setText("GIF saved successfully.");
    msgBox.exec();
  }
  ++frame_;
}

void View::GifButtonClicked_() {
  gifFileName_ = QFileDialog::getSaveFileName(
      this, tr("Save file"), GetDir_() + "/images", tr("GIF (*.gif)"));
  if (!gifFileName_.isEmpty()) {
    gifIm_ = new QGifImage;
    gifIm_->setDefaultDelay(10);
    GifTimer_();
  } else {
    QMessageBox::warning(this, "", "Failed to save GIF.");
  }
}
}  // namespace awfl
