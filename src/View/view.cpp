#include "view.h"

#include "ui_view.h"

namespace awfl {
View::View(Controller* cont, QWidget* parent)
    : QMainWindow(parent), ui_(new Ui::View), controller_(cont) {
  ui_->setupUi(this);
  ui_->openGLWidget->SetController(cont);

  connect(ui_->dSBox_Xt, SIGNAL(valueChanged(double)), this,
          SLOT(TranslationValueChangedX_(double)));
  connect(ui_->dSBox_Yt, SIGNAL(valueChanged(double)), this,
          SLOT(TranslationValueChangedY_(double)));
  connect(ui_->dSBox_Zt, SIGNAL(valueChanged(double)), this,
          SLOT(TranslationValueChangedZ_(double)));

  connect(ui_->dSBox_Xr, SIGNAL(valueChanged(double)), this,
          SLOT(RotationValueChangedX_(double)));
  connect(ui_->dSBox_Yr, SIGNAL(valueChanged(double)), this,
          SLOT(RotationValueChangedY_(double)));
  connect(ui_->dSBox_Zr, SIGNAL(valueChanged(double)), this,
          SLOT(RotationValueChangedZ_(double)));

  connect(ui_->horizontalSlider_Scale, SIGNAL(valueChanged(int)), this,
          SLOT(ScaleValueChanged_(int)));

  connect(ui_->comboBox_V, SIGNAL(activated(int)), this,
          SLOT(VerticesTypeActivated_(int)));
  connect(ui_->comboBox_L, SIGNAL(activated(int)), this,
          SLOT(LinesTypeActivated_(int)));

  connect(ui_->horizontalSlider_V, SIGNAL(valueChanged(int)), this,
          SLOT(SizeVerticesChanged_(int)));
  connect(ui_->horizontalSlider_L, SIGNAL(valueChanged(int)), this,
          SLOT(SizeLinesChanged_(int)));

  connect(ui_->comboBox_P, SIGNAL(activated(int)), this,
          SLOT(ProjectionTypeActivated_(int)));

  connect(ui_->pushButton_file, SIGNAL(clicked()), this,
          SLOT(OpenfileButtonClicked_()));

  connect(ui_->pushButton_colorV, SIGNAL(clicked()), this,
          SLOT(ColorVerticesClicked_()));
  connect(ui_->pushButton_colorL, SIGNAL(clicked()), this,
          SLOT(ColorLinesClicked_()));
  connect(ui_->pushButton_cBG, SIGNAL(clicked()), this,
          SLOT(ColorBackgroundClicked_()));

  connect(ui_->pushButton_clear, SIGNAL(clicked()), this,
          SLOT(ClearButtonClicked_()));
  connect(ui_->pushButton_allclear, SIGNAL(clicked()), this,
          SLOT(ClearAllButtonClicked_()));

  connect(ui_->pushButton_screen, SIGNAL(clicked()), this,
          SLOT(ScreenButtonClicked_()));

  connect(ui_->pushButton_gif, SIGNAL(clicked()), this,
          SLOT(GifButtonClicked_()));

  LoadSettings_();

  timer_ = new QTimer(0);
  connect(timer_, SIGNAL(timeout()), this, SLOT(GifCreate_()));
}

View::~View() {
  SaveSettings_();
  delete timer_;
  delete ui_;
}

void View::ReadFile_(QString filePath) {
  ui_->openGLWidget->OpenFile(filePath);

  int index = filePath.lastIndexOf("/", -1);
  ui_->label_filename->setText("•File name: " +
                               filePath.right(filePath.length() - index - 1));
  ui_->label_numV->setText(
      "•Number of vertices: " +
      QString::number(controller_->GetVerticesNumbers() / 3));
  ui_->label_numL->setText("•Number of edges: " +
                           QString::number(controller_->GetEdgesNumbers() / 2));
}

void View::OpenfileButtonClicked_() {
  QString fileName = QFileDialog::getOpenFileName(
      0, tr("Open file"), GetDir_() + "/models", tr("Object files (*.obj)"));
  ui_->openGLWidget->SetFileName(fileName);
  if (fileName.isEmpty()) {
    return;
  }
  ReadFile_(fileName);
  ui_->openGLWidget->update();
}

QString View::GetDir_() const {
  QString path = QCoreApplication::applicationDirPath();
  auto pos = path.indexOf("/build", 0);
  return path.left(pos);
}
}  // namespace awfl
