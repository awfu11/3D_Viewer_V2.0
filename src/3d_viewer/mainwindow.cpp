#include "mainwindow.h"

#include "ui_mainwindow.h"

extern "C" {
#include "gif.h"
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  connect(ui->dSBox_Xt, SIGNAL(valueChanged(double)), this,
          SLOT(translationValue_changed_X(double)));
  connect(ui->dSBox_Yt, SIGNAL(valueChanged(double)), this,
          SLOT(translationValue_changed_Y(double)));
  connect(ui->dSBox_Zt, SIGNAL(valueChanged(double)), this,
          SLOT(translationValue_changed_Z(double)));

  connect(ui->dSBox_Xr, SIGNAL(valueChanged(double)), this,
          SLOT(rotationValue_changed_X(double)));
  connect(ui->dSBox_Yr, SIGNAL(valueChanged(double)), this,
          SLOT(rotationValue_changed_Y(double)));
  connect(ui->dSBox_Zr, SIGNAL(valueChanged(double)), this,
          SLOT(rotationValue_changed_Z(double)));

  connect(ui->horizontalSlider_Scale, SIGNAL(valueChanged(int)), this,
          SLOT(scaleValue_changed(int)));

  connect(ui->comboBox_V, SIGNAL(activated(int)), this,
          SLOT(verticesType_activated(int)));
  connect(ui->comboBox_L, SIGNAL(activated(int)), this,
          SLOT(linesType_activated(int)));

  connect(ui->horizontalSlider_V, SIGNAL(valueChanged(int)), this,
          SLOT(sizeVertices_changed(int)));
  connect(ui->horizontalSlider_L, SIGNAL(valueChanged(int)), this,
          SLOT(sizeLines_changed(int)));

  connect(ui->comboBox_P, SIGNAL(activated(int)), this,
          SLOT(projectionType_activated(int)));

  connect(ui->pushButton_file, SIGNAL(clicked()), this,
          SLOT(openfileButton_clicked()));

  connect(ui->pushButton_clear, SIGNAL(clicked()), this,
          SLOT(clearButton_clicked()));
  connect(ui->pushButton_allclear, SIGNAL(clicked()), this,
          SLOT(clearAllButton_clicked()));

  connect(ui->pushButton_colorV, SIGNAL(clicked()), this,
          SLOT(colorVertices_clicked()));
  connect(ui->pushButton_colorL, SIGNAL(clicked()), this,
          SLOT(colorLines_clicked()));
  connect(ui->pushButton_cBG, SIGNAL(clicked()), this,
          SLOT(colorBackground_clicked()));

  connect(qApp, SIGNAL(aboutToQuit()), this, SLOT(onQuit()));
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::translationValue_changed_X(double arg1) {
  ui->openGLWidget->translation[0] = arg1;
  ui->openGLWidget->update();
}

void MainWindow::translationValue_changed_Y(double arg1) {
  ui->openGLWidget->translation[1] = arg1;
  ui->openGLWidget->update();
}

void MainWindow::translationValue_changed_Z(double arg1) {
  ui->openGLWidget->translation[2] = arg1;
  ui->openGLWidget->update();
}

void MainWindow::rotationValue_changed_X(double arg1) {
  ui->openGLWidget->rotation[0] = arg1 / 180.0 * M_PI;
  ui->openGLWidget->update();
}

void MainWindow::rotationValue_changed_Y(double arg1) {
  ui->openGLWidget->rotation[1] = arg1 / 180.0 * M_PI;
  ui->openGLWidget->update();
}

void MainWindow::rotationValue_changed_Z(double arg1) {
  ui->openGLWidget->rotation[2] = arg1 / 180.0 * M_PI;
  ui->openGLWidget->update();
}

void MainWindow::scaleValue_changed(int value) {
  if (ui->openGLWidget->scale == (double)value) {
    ui->openGLWidget->scale = 1.0;
  } else {
    ui->openGLWidget->scale = (double)value;
  }
  ui->openGLWidget->update();
}

void MainWindow::verticesType_activated(int index) {
  ui->openGLWidget->typeVertices = index;
  ui->openGLWidget->update();
}

void MainWindow::sizeVertices_changed(int value) {
  ui->openGLWidget->sizeVertices = (double)value;
  ui->openGLWidget->update();
}

void MainWindow::linesType_activated(int index) {
  ui->openGLWidget->typeLines = index;
  ui->openGLWidget->update();
}

void MainWindow::sizeLines_changed(int value) {
  ui->openGLWidget->sizeLines = (double)value;
  ui->openGLWidget->update();
}

void MainWindow::projectionType_activated(int index) {
  ui->openGLWidget->projection = index;
  ui->openGLWidget->update();
}

void MainWindow::openfileButton_clicked() {
  // QString fileName = QFileDialog::getOpenFileName(
  //     0, tr("Open file"), QDir::currentPath() + "/models",
  //     tr("Object files (*.obj)"));

  QString temp = QCoreApplication::applicationDirPath();
  temp.resize(temp.size() - 38);
  QString fileName = QFileDialog::getOpenFileName(
      0, tr("Open file"), temp + "/models", tr("Object files (*.obj)"));

  int index = fileName.lastIndexOf("/", -1);
  ui->label_filename->setText("•File name: " +
                              fileName.right(fileName.length() - index - 1));
  ui->openGLWidget->filePath = fileName;
  ui->openGLWidget->openFile();
  ui->label_numV->setText("•Number of vertices: " +
                          QString::number(ui->openGLWidget->numV));
  ui->label_numL->setText("•Number of edges: " +
                          QString::number(ui->openGLWidget->numL));
  ui->openGLWidget->update();
}

void MainWindow::clearButton_clicked() {
  ui->dSBox_Xr->setValue(0.0);
  ui->dSBox_Yr->setValue(0.0);
  ui->dSBox_Zr->setValue(0.0);

  ui->dSBox_Xt->setValue(0.0);
  ui->dSBox_Yt->setValue(0.0);
  ui->dSBox_Zt->setValue(0.0);

  ui->horizontalSlider_Scale->setValue(1);

  ui->horizontalSlider_V->setValue(1);
  verticesType_activated(1);
  ui->comboBox_V->setCurrentIndex(1);

  ui->horizontalSlider_L->setValue(1);
  linesType_activated(1);
  ui->comboBox_L->setCurrentIndex(1);

  projectionType_activated(0);
  ui->comboBox_P->setCurrentIndex(0);
  ui->openGLWidget->update();
}

void MainWindow::clearAllButton_clicked() {
  clearButton_clicked();
  ui->openGLWidget->colorVertices.setRedF(1.0f);
  ui->openGLWidget->colorVertices.setGreenF(1.0f);
  ui->openGLWidget->colorVertices.setBlueF(1.0f);

  ui->openGLWidget->colorLines.setRedF(1.0f);
  ui->openGLWidget->colorLines.setGreenF(1.0f);
  ui->openGLWidget->colorLines.setBlueF(1.0f);

  ui->openGLWidget->colorBackground.setRedF(0.0f);
  ui->openGLWidget->colorBackground.setGreenF(0.0f);
  ui->openGLWidget->colorBackground.setBlueF(0.0f);

  ui->openGLWidget->filePath = "";
  ui->openGLWidget->openFile();
  ui->label_filename->setText("•File name: ");
  ui->label_numV->setText("•Number of vertices: ");
  ui->label_numL->setText("•Number of edges: ");
  ui->openGLWidget->update();
}

void MainWindow::colorVertices_clicked() {
  QColor colour = QColorDialog::getColor(Qt::white, this, "Select color:");
  ui->openGLWidget->colorVertices = colour;
  ui->openGLWidget->update();
}

void MainWindow::colorLines_clicked() {
  QColor colour = QColorDialog::getColor(Qt::white, this, "Select color:");
  ui->openGLWidget->colorLines = colour;
  ui->openGLWidget->update();
}

void MainWindow::colorBackground_clicked() {
  QColor colour = QColorDialog::getColor(Qt::white, this, "Select color:");
  ui->openGLWidget->colorBackground = colour;
  ui->openGLWidget->update();
}

void MainWindow::on_pushButton_screen_clicked() {
  QImage img(ui->openGLWidget->size(), QImage::Format_RGB32);
  QPainter painter(&img);

  // QString fileName = QFileDialog::getSaveFileName(
  //     this, tr("Save file"), QDir::currentPath() + "/images",
  //     tr("JPG (*.jpg);; BMP (*.bmp)"));

  QString temp = QCoreApplication::applicationDirPath();
  temp.resize(temp.size() - 38);
  QString fileName = QFileDialog::getSaveFileName(
      this, tr("Save file"), temp + "/images", tr("JPG (*.jpg);; BMP (*.bmp)"));

  bool res = false;
  ui->openGLWidget->render(&painter);
  res = img.save(fileName);
  if (res == true) {
    QMessageBox msgBox;
    msgBox.setText("Screenshot saved successfully.");
    msgBox.exec();
  } else {
    QMessageBox::warning(this, "", "Failed to save screenshot.");
  }
}

void MainWindow::on_pushButton_gif_clicked() {
  // QString fileName = QFileDialog::getSaveFileName(
  //     this, tr("Save gif"), QDir::currentPath() + "/images", tr("GIF
  //     (*.gif)"));

  QString temp = QCoreApplication::applicationDirPath();
  temp.resize(temp.size() - 38);
  QString fileName = QFileDialog::getSaveFileName(
      this, tr("Save gif"), temp + "/images", tr("GIF (*.gif)"));

  if (!fileName.isEmpty()) {
    QImage img(ui->openGLWidget->size(), QImage::Format_RGB32);
    QPainter painter(&img);
    QImage img640_480;
    QTime dieTime;
    int width = 640;
    int height = 480;
    GifWriter gif;
    QByteArray ba = fileName.toLocal8Bit();
    const char *c_str = ba.data();
    GifBegin(&gif, c_str, width, height, 100);

    for (int i = 0; i < 50; ++i) {
      ui->openGLWidget->render(&painter);
      img640_480 = img.scaled(QSize(640, 480));
      GifWriteFrame(&gif, img640_480.bits(), width, height, 100);
      dieTime = QTime::currentTime().addMSecs(100);
      while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }

    GifEnd(&gif);
    QMessageBox msgBox;
    msgBox.setText("GIF saved successfully.");
    msgBox.exec();
  } else {
    QMessageBox::warning(this, "", "Failed to save gif.");
  }
}

void MainWindow::start_app() {
  QString fileName;
  int index;
  // QSettings settings(QDir::currentPath() + "/settings.ini",
  //                    QSettings::IniFormat);

  QString temp = QCoreApplication::applicationDirPath();
  temp.resize(temp.size() - 38);
  QSettings settings(temp + "/settings.ini", QSettings::IniFormat);

  settings.beginGroup("Settings");

  ui->openGLWidget->projection = settings.value("comboBox_P").toInt();
  ui->comboBox_P->setCurrentIndex(ui->openGLWidget->projection);

  ui->dSBox_Xr->setValue(settings.value("dSBox_Xr").toDouble());
  ui->dSBox_Yr->setValue(settings.value("dSBox_Xr").toDouble());
  ui->dSBox_Zr->setValue(settings.value("dSBox_Xr").toDouble());

  ui->dSBox_Xt->setValue(settings.value("dSBox_Xt").toDouble());
  ui->dSBox_Yt->setValue(settings.value("dSBox_Yt").toDouble());
  ui->dSBox_Zt->setValue(settings.value("dSBox_Zt").toDouble());

  ui->horizontalSlider_Scale->setValue(
      settings.value("horizontalSlider_Scale").toInt());

  ui->horizontalSlider_V->setValue(
      settings.value("horizontalSlider_V").toInt());

  ui->horizontalSlider_L->setValue(
      settings.value("horizontalSlider_L").toInt());
  ui->openGLWidget->typeLines = settings.value("comboBox_L", 1).toInt();
  ui->comboBox_L->setCurrentIndex(ui->openGLWidget->typeLines);

  fileName = settings.value("filePath").toString();
  if (!fileName.isEmpty()) {
    index = fileName.lastIndexOf("/", -1);
    ui->label_filename->setText("•File name: " +
                                fileName.right(fileName.length() - index - 1));
    ui->openGLWidget->filePath = fileName;
    ui->openGLWidget->openFile();
    ui->label_numV->setText("•Number of vertices: " +
                            QString::number(ui->openGLWidget->numV));
    ui->label_numL->setText("•Number of edges: " +
                            QString::number(ui->openGLWidget->numL));
  }

  ui->openGLWidget->colorVertices =
      settings.value("colorVertices", QColor(Qt::white)).value<QColor>();
  ui->openGLWidget->colorLines =
      settings.value("colorLines", QColor(Qt::white)).value<QColor>();
  ui->openGLWidget->colorBackground =
      settings.value("colorBackground", QColor(Qt::black)).value<QColor>();

  settings.endGroup();

  ui->openGLWidget->update();
}

void MainWindow::onQuit() {
  // QSettings settings(QDir::currentPath() + "/settings.ini",
  //                    QSettings::IniFormat);

  QString temp = QCoreApplication::applicationDirPath();
  temp.resize(temp.size() - 38);
  QSettings settings(temp + "/settings.ini", QSettings::IniFormat);

  settings.beginGroup("Settings");

  settings.setValue("filePath", ui->openGLWidget->filePath);

  settings.setValue("dSBox_Xt", ui->dSBox_Xt->value());
  settings.setValue("dSBox_Yt", ui->dSBox_Yt->value());
  settings.setValue("dSBox_Zt", ui->dSBox_Zt->value());

  settings.setValue("dSBox_Xr", ui->dSBox_Xr->value());
  settings.setValue("dSBox_Yr", ui->dSBox_Yr->value());
  settings.setValue("dSBox_Zr", ui->dSBox_Zr->value());

  settings.setValue("horizontalSlider_Scale",
                    ui->horizontalSlider_Scale->value());
  settings.setValue("horizontalSlider_V", ui->horizontalSlider_V->value());
  settings.setValue("horizontalSlider_L", ui->horizontalSlider_L->value());

  settings.setValue("colorVertices", ui->openGLWidget->colorVertices);
  settings.setValue("colorLines", ui->openGLWidget->colorLines);
  settings.setValue("colorBackground", ui->openGLWidget->colorBackground);

  settings.setValue("comboBox_P", ui->comboBox_P->currentIndex());
  settings.setValue("comboBox_L", ui->comboBox_L->currentIndex());

  settings.endGroup();
}
