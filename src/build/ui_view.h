/********************************************************************************
** Form generated from reading UI file 'view.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEW_H
#define UI_VIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>
#include <View/glview.h>

QT_BEGIN_NAMESPACE

class Ui_View
{
public:
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_projection;
    QLabel *label_r;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_gif;
    QPushButton *pushButton_screen;
    QLabel *label_numL;
    QComboBox *comboBox_P;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_X_2;
    QDoubleSpinBox *dSBox_Xr;
    QLabel *label_Y_2;
    QDoubleSpinBox *dSBox_Yr;
    QLabel *label_Z_2;
    QDoubleSpinBox *dSBox_Zr;
    QFrame *line_3;
    QLabel *label_numV;
    QLabel *label_s;
    QLabel *label_info;
    QHBoxLayout *horizontalLayout;
    QLabel *label_Xt;
    QDoubleSpinBox *dSBox_Xt;
    QLabel *label_Y;
    QDoubleSpinBox *dSBox_Yt;
    QLabel *label_Z;
    QDoubleSpinBox *dSBox_Zt;
    QPushButton *pushButton_cBG;
    QLabel *label_vertices;
    QComboBox *comboBox_V;
    QPushButton *pushButton_colorV;
    QFrame *line_8;
    QLabel *label_filename;
    QComboBox *comboBox_L;
    QPushButton *pushButton_file;
    QFrame *line_5;
    QFrame *line_6;
    QFrame *line;
    QLabel *label_edges;
    QPushButton *pushButton_colorL;
    QFrame *line_7;
    QFrame *line_4;
    QFrame *line_2;
    QLabel *label;
    QLabel *label_t;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton_clear;
    QPushButton *pushButton_allclear;
    QSlider *horizontalSlider_V;
    QSlider *horizontalSlider_L;
    QSlider *horizontalSlider_Scale;
    GLView *openGLWidget;

    void setupUi(QMainWindow *View)
    {
        if (View->objectName().isEmpty())
            View->setObjectName("View");
        View->resize(1384, 771);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(138);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(View->sizePolicy().hasHeightForWidth());
        View->setSizePolicy(sizePolicy);
        View->setMinimumSize(QSize(1384, 771));
        View->setMaximumSize(QSize(1384, 771));
        centralwidget = new QWidget(View);
        centralwidget->setObjectName("centralwidget");
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(1040, 10, 340, 751));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_projection = new QLabel(gridLayoutWidget);
        label_projection->setObjectName("label_projection");
        QFont font;
        font.setPointSize(16);
        label_projection->setFont(font);

        gridLayout->addWidget(label_projection, 15, 0, 1, 1);

        label_r = new QLabel(gridLayoutWidget);
        label_r->setObjectName("label_r");
        label_r->setFont(font);

        gridLayout->addWidget(label_r, 10, 0, 1, 3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        pushButton_gif = new QPushButton(gridLayoutWidget);
        pushButton_gif->setObjectName("pushButton_gif");
        pushButton_gif->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: rgb(0, 0, 0);\n"
"	background-color: rgb(215, 232, 255);\n"
"}\n"
"\n"
"QPushButton::pressed {\n"
"	color: rgb(1, 1, 1);\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));

        horizontalLayout_3->addWidget(pushButton_gif);

        pushButton_screen = new QPushButton(gridLayoutWidget);
        pushButton_screen->setObjectName("pushButton_screen");
        pushButton_screen->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: rgb(0, 0, 0);\n"
"	background-color: rgb(215, 232, 255);\n"
"}\n"
"\n"
"QPushButton::pressed {\n"
"	color: rgb(1, 1, 1);\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));

        horizontalLayout_3->addWidget(pushButton_screen);


        gridLayout->addLayout(horizontalLayout_3, 5, 0, 1, 3);

        label_numL = new QLabel(gridLayoutWidget);
        label_numL->setObjectName("label_numL");
        QFont font1;
        font1.setPointSize(13);
        label_numL->setFont(font1);

        gridLayout->addWidget(label_numL, 3, 0, 1, 3);

        comboBox_P = new QComboBox(gridLayoutWidget);
        comboBox_P->addItem(QString());
        comboBox_P->addItem(QString());
        comboBox_P->setObjectName("comboBox_P");
        comboBox_P->setMaxVisibleItems(1);

        gridLayout->addWidget(comboBox_P, 15, 1, 1, 2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_X_2 = new QLabel(gridLayoutWidget);
        label_X_2->setObjectName("label_X_2");
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_X_2->sizePolicy().hasHeightForWidth());
        label_X_2->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(label_X_2);

        dSBox_Xr = new QDoubleSpinBox(gridLayoutWidget);
        dSBox_Xr->setObjectName("dSBox_Xr");
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(dSBox_Xr->sizePolicy().hasHeightForWidth());
        dSBox_Xr->setSizePolicy(sizePolicy2);
        dSBox_Xr->setFocusPolicy(Qt::ClickFocus);
        dSBox_Xr->setAlignment(Qt::AlignCenter);
        dSBox_Xr->setButtonSymbols(QAbstractSpinBox::NoButtons);
        dSBox_Xr->setMinimum(-360.000000000000000);
        dSBox_Xr->setMaximum(360.000000000000000);

        horizontalLayout_2->addWidget(dSBox_Xr);

        label_Y_2 = new QLabel(gridLayoutWidget);
        label_Y_2->setObjectName("label_Y_2");
        sizePolicy1.setHeightForWidth(label_Y_2->sizePolicy().hasHeightForWidth());
        label_Y_2->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(label_Y_2);

        dSBox_Yr = new QDoubleSpinBox(gridLayoutWidget);
        dSBox_Yr->setObjectName("dSBox_Yr");
        sizePolicy2.setHeightForWidth(dSBox_Yr->sizePolicy().hasHeightForWidth());
        dSBox_Yr->setSizePolicy(sizePolicy2);
        dSBox_Yr->setFocusPolicy(Qt::ClickFocus);
        dSBox_Yr->setAlignment(Qt::AlignCenter);
        dSBox_Yr->setButtonSymbols(QAbstractSpinBox::NoButtons);
        dSBox_Yr->setMinimum(-360.000000000000000);
        dSBox_Yr->setMaximum(360.000000000000000);

        horizontalLayout_2->addWidget(dSBox_Yr);

        label_Z_2 = new QLabel(gridLayoutWidget);
        label_Z_2->setObjectName("label_Z_2");
        sizePolicy1.setHeightForWidth(label_Z_2->sizePolicy().hasHeightForWidth());
        label_Z_2->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(label_Z_2);

        dSBox_Zr = new QDoubleSpinBox(gridLayoutWidget);
        dSBox_Zr->setObjectName("dSBox_Zr");
        sizePolicy2.setHeightForWidth(dSBox_Zr->sizePolicy().hasHeightForWidth());
        dSBox_Zr->setSizePolicy(sizePolicy2);
        dSBox_Zr->setFocusPolicy(Qt::ClickFocus);
        dSBox_Zr->setAlignment(Qt::AlignCenter);
        dSBox_Zr->setButtonSymbols(QAbstractSpinBox::NoButtons);
        dSBox_Zr->setMinimum(-360.000000000000000);
        dSBox_Zr->setMaximum(360.000000000000000);

        horizontalLayout_2->addWidget(dSBox_Zr);


        gridLayout->addLayout(horizontalLayout_2, 11, 0, 1, 3);

        line_3 = new QFrame(gridLayoutWidget);
        line_3->setObjectName("line_3");
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_3, 14, 0, 1, 3);

        label_numV = new QLabel(gridLayoutWidget);
        label_numV->setObjectName("label_numV");
        label_numV->setFont(font1);

        gridLayout->addWidget(label_numV, 2, 0, 1, 3);

        label_s = new QLabel(gridLayoutWidget);
        label_s->setObjectName("label_s");
        label_s->setFont(font);

        gridLayout->addWidget(label_s, 13, 0, 1, 1);

        label_info = new QLabel(gridLayoutWidget);
        label_info->setObjectName("label_info");
        label_info->setFont(font);

        gridLayout->addWidget(label_info, 0, 0, 1, 3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_Xt = new QLabel(gridLayoutWidget);
        label_Xt->setObjectName("label_Xt");
        sizePolicy1.setHeightForWidth(label_Xt->sizePolicy().hasHeightForWidth());
        label_Xt->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(label_Xt);

        dSBox_Xt = new QDoubleSpinBox(gridLayoutWidget);
        dSBox_Xt->setObjectName("dSBox_Xt");
        sizePolicy2.setHeightForWidth(dSBox_Xt->sizePolicy().hasHeightForWidth());
        dSBox_Xt->setSizePolicy(sizePolicy2);
        dSBox_Xt->setFocusPolicy(Qt::ClickFocus);
        dSBox_Xt->setAlignment(Qt::AlignCenter);
        dSBox_Xt->setButtonSymbols(QAbstractSpinBox::NoButtons);
        dSBox_Xt->setMinimum(-100.000000000000000);
        dSBox_Xt->setMaximum(100.000000000000000);

        horizontalLayout->addWidget(dSBox_Xt);

        label_Y = new QLabel(gridLayoutWidget);
        label_Y->setObjectName("label_Y");
        sizePolicy1.setHeightForWidth(label_Y->sizePolicy().hasHeightForWidth());
        label_Y->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(label_Y);

        dSBox_Yt = new QDoubleSpinBox(gridLayoutWidget);
        dSBox_Yt->setObjectName("dSBox_Yt");
        sizePolicy2.setHeightForWidth(dSBox_Yt->sizePolicy().hasHeightForWidth());
        dSBox_Yt->setSizePolicy(sizePolicy2);
        dSBox_Yt->setFocusPolicy(Qt::ClickFocus);
        dSBox_Yt->setAlignment(Qt::AlignCenter);
        dSBox_Yt->setButtonSymbols(QAbstractSpinBox::NoButtons);
        dSBox_Yt->setMinimum(-100.000000000000000);
        dSBox_Yt->setMaximum(100.000000000000000);

        horizontalLayout->addWidget(dSBox_Yt);

        label_Z = new QLabel(gridLayoutWidget);
        label_Z->setObjectName("label_Z");
        sizePolicy1.setHeightForWidth(label_Z->sizePolicy().hasHeightForWidth());
        label_Z->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(label_Z);

        dSBox_Zt = new QDoubleSpinBox(gridLayoutWidget);
        dSBox_Zt->setObjectName("dSBox_Zt");
        sizePolicy2.setHeightForWidth(dSBox_Zt->sizePolicy().hasHeightForWidth());
        dSBox_Zt->setSizePolicy(sizePolicy2);
        dSBox_Zt->setFocusPolicy(Qt::ClickFocus);
        dSBox_Zt->setAlignment(Qt::AlignCenter);
        dSBox_Zt->setButtonSymbols(QAbstractSpinBox::NoButtons);
        dSBox_Zt->setMinimum(-100.000000000000000);
        dSBox_Zt->setMaximum(100.000000000000000);

        horizontalLayout->addWidget(dSBox_Zt);


        gridLayout->addLayout(horizontalLayout, 8, 0, 1, 3);

        pushButton_cBG = new QPushButton(gridLayoutWidget);
        pushButton_cBG->setObjectName("pushButton_cBG");
        pushButton_cBG->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: rgb(0, 0, 0);\n"
"	background-color: rgb(228, 255, 244);\n"
"}\n"
"\n"
"QPushButton::pressed {\n"
"	color: rgb(1, 1, 1);\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));

        gridLayout->addWidget(pushButton_cBG, 17, 2, 1, 1);

        label_vertices = new QLabel(gridLayoutWidget);
        label_vertices->setObjectName("label_vertices");
        label_vertices->setFont(font);

        gridLayout->addWidget(label_vertices, 19, 0, 1, 2);

        comboBox_V = new QComboBox(gridLayoutWidget);
        comboBox_V->addItem(QString());
        comboBox_V->addItem(QString());
        comboBox_V->addItem(QString());
        comboBox_V->setObjectName("comboBox_V");
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(comboBox_V->sizePolicy().hasHeightForWidth());
        comboBox_V->setSizePolicy(sizePolicy3);
        comboBox_V->setMinimumSize(QSize(0, 0));
        comboBox_V->setMaximumSize(QSize(16777215, 16777215));
        QFont font2;
        font2.setStyleStrategy(QFont::PreferDefault);
        comboBox_V->setFont(font2);
        comboBox_V->setFocusPolicy(Qt::NoFocus);
        comboBox_V->setEditable(false);
        comboBox_V->setMaxVisibleItems(2);
        comboBox_V->setMaxCount(10);
        comboBox_V->setSizeAdjustPolicy(QComboBox::AdjustToContentsOnFirstShow);
        comboBox_V->setFrame(true);
        comboBox_V->setModelColumn(0);

        gridLayout->addWidget(comboBox_V, 20, 2, 1, 1);

        pushButton_colorV = new QPushButton(gridLayoutWidget);
        pushButton_colorV->setObjectName("pushButton_colorV");
        pushButton_colorV->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: rgb(0, 0, 0);\n"
"	background-color: rgb(228, 255, 244);\n"
"}\n"
"\n"
"QPushButton::pressed {\n"
"	color: rgb(1, 1, 1);\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));

        gridLayout->addWidget(pushButton_colorV, 19, 2, 1, 1);

        line_8 = new QFrame(gridLayoutWidget);
        line_8->setObjectName("line_8");
        line_8->setFrameShape(QFrame::HLine);
        line_8->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_8, 6, 0, 1, 3);

        label_filename = new QLabel(gridLayoutWidget);
        label_filename->setObjectName("label_filename");
        label_filename->setFont(font1);

        gridLayout->addWidget(label_filename, 1, 0, 1, 3);

        comboBox_L = new QComboBox(gridLayoutWidget);
        comboBox_L->addItem(QString());
        comboBox_L->addItem(QString());
        comboBox_L->addItem(QString());
        comboBox_L->setObjectName("comboBox_L");
        sizePolicy3.setHeightForWidth(comboBox_L->sizePolicy().hasHeightForWidth());
        comboBox_L->setSizePolicy(sizePolicy3);
        comboBox_L->setMinimumSize(QSize(0, 0));
        comboBox_L->setMaximumSize(QSize(16777215, 16777215));
        comboBox_L->setFont(font2);
        comboBox_L->setFocusPolicy(Qt::NoFocus);
        comboBox_L->setEditable(false);
        comboBox_L->setMaxVisibleItems(2);
        comboBox_L->setMaxCount(10);
        comboBox_L->setSizeAdjustPolicy(QComboBox::AdjustToContentsOnFirstShow);
        comboBox_L->setFrame(true);
        comboBox_L->setModelColumn(0);

        gridLayout->addWidget(comboBox_L, 23, 2, 1, 1);

        pushButton_file = new QPushButton(gridLayoutWidget);
        pushButton_file->setObjectName("pushButton_file");
        pushButton_file->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: rgb(0, 0, 0);\n"
"	background-color: rgb(239, 225, 255);\n"
"}\n"
"\n"
"QPushButton::pressed {\n"
"	color: rgb(1, 1, 1);\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));

        gridLayout->addWidget(pushButton_file, 4, 0, 1, 3);

        line_5 = new QFrame(gridLayoutWidget);
        line_5->setObjectName("line_5");
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_5, 16, 0, 1, 3);

        line_6 = new QFrame(gridLayoutWidget);
        line_6->setObjectName("line_6");
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_6, 24, 0, 1, 3);

        line = new QFrame(gridLayoutWidget);
        line->setObjectName("line");
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 9, 0, 1, 3);

        label_edges = new QLabel(gridLayoutWidget);
        label_edges->setObjectName("label_edges");
        label_edges->setFont(font);

        gridLayout->addWidget(label_edges, 22, 0, 1, 2);

        pushButton_colorL = new QPushButton(gridLayoutWidget);
        pushButton_colorL->setObjectName("pushButton_colorL");
        pushButton_colorL->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: rgb(0, 0, 0);\n"
"	background-color: rgb(228, 255, 244);\n"
"}\n"
"\n"
"QPushButton::pressed {\n"
"	color: rgb(1, 1, 1);\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));

        gridLayout->addWidget(pushButton_colorL, 22, 2, 1, 1);

        line_7 = new QFrame(gridLayoutWidget);
        line_7->setObjectName("line_7");
        line_7->setFrameShape(QFrame::HLine);
        line_7->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_7, 18, 0, 1, 3);

        line_4 = new QFrame(gridLayoutWidget);
        line_4->setObjectName("line_4");
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_4, 21, 0, 1, 3);

        line_2 = new QFrame(gridLayoutWidget);
        line_2->setObjectName("line_2");
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_2, 12, 0, 1, 3);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName("label");
        label->setFont(font);

        gridLayout->addWidget(label, 17, 0, 1, 2);

        label_t = new QLabel(gridLayoutWidget);
        label_t->setObjectName("label_t");
        label_t->setFont(font);

        gridLayout->addWidget(label_t, 7, 0, 1, 3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        pushButton_clear = new QPushButton(gridLayoutWidget);
        pushButton_clear->setObjectName("pushButton_clear");
        pushButton_clear->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: rgb(0, 0, 0);\n"
"	background-color: rgb(255, 231, 231);\n"
"}\n"
"\n"
"QPushButton::pressed {\n"
"	color: rgb(1, 1, 1);\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));

        horizontalLayout_4->addWidget(pushButton_clear);

        pushButton_allclear = new QPushButton(gridLayoutWidget);
        pushButton_allclear->setObjectName("pushButton_allclear");
        pushButton_allclear->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: rgb(0, 0, 0);\n"
"	background-color: rgb(255, 231, 231);\n"
"}\n"
"\n"
"QPushButton::pressed {\n"
"	color: rgb(1, 1, 1);\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));

        horizontalLayout_4->addWidget(pushButton_allclear);


        gridLayout->addLayout(horizontalLayout_4, 25, 0, 1, 3);

        horizontalSlider_V = new QSlider(gridLayoutWidget);
        horizontalSlider_V->setObjectName("horizontalSlider_V");
        horizontalSlider_V->setMinimum(1);
        horizontalSlider_V->setMaximum(25);
        horizontalSlider_V->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider_V, 20, 0, 1, 2);

        horizontalSlider_L = new QSlider(gridLayoutWidget);
        horizontalSlider_L->setObjectName("horizontalSlider_L");
        horizontalSlider_L->setMinimum(1);
        horizontalSlider_L->setMaximum(25);
        horizontalSlider_L->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider_L, 23, 0, 1, 2);

        horizontalSlider_Scale = new QSlider(gridLayoutWidget);
        horizontalSlider_Scale->setObjectName("horizontalSlider_Scale");
        horizontalSlider_Scale->setMinimum(1);
        horizontalSlider_Scale->setMaximum(10);
        horizontalSlider_Scale->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider_Scale, 13, 1, 1, 2);

        openGLWidget = new GLView(centralwidget);
        openGLWidget->setObjectName("openGLWidget");
        openGLWidget->setGeometry(QRect(10, 10, 1021, 751));
        View->setCentralWidget(centralwidget);

        retranslateUi(View);

        comboBox_V->setCurrentIndex(1);
        comboBox_L->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(View);
    } // setupUi

    void retranslateUi(QMainWindow *View)
    {
        View->setWindowTitle(QCoreApplication::translate("View", "3D Viewer v2.0", nullptr));
        label_projection->setText(QCoreApplication::translate("View", "Projection", nullptr));
        label_r->setText(QCoreApplication::translate("View", "Rotation", nullptr));
        pushButton_gif->setText(QCoreApplication::translate("View", "GIF", nullptr));
        pushButton_screen->setText(QCoreApplication::translate("View", "Screenshot", nullptr));
        label_numL->setText(QCoreApplication::translate("View", "\342\200\242Number of edges: ", nullptr));
        comboBox_P->setItemText(0, QCoreApplication::translate("View", "Central projection", nullptr));
        comboBox_P->setItemText(1, QCoreApplication::translate("View", "Parallel projection", nullptr));

        label_X_2->setText(QCoreApplication::translate("View", "X", nullptr));
        label_Y_2->setText(QCoreApplication::translate("View", "Y", nullptr));
        label_Z_2->setText(QCoreApplication::translate("View", "Z", nullptr));
        label_numV->setText(QCoreApplication::translate("View", "\342\200\242Number of vertices: ", nullptr));
        label_s->setText(QCoreApplication::translate("View", "Scale", nullptr));
        label_info->setText(QCoreApplication::translate("View", "Information about the uploaded model:", nullptr));
        label_Xt->setText(QCoreApplication::translate("View", "X", nullptr));
        label_Y->setText(QCoreApplication::translate("View", "Y", nullptr));
        label_Z->setText(QCoreApplication::translate("View", "Z", nullptr));
        pushButton_cBG->setText(QCoreApplication::translate("View", "Set color", nullptr));
        label_vertices->setText(QCoreApplication::translate("View", "Vertices", nullptr));
        comboBox_V->setItemText(0, QCoreApplication::translate("View", "None", nullptr));
        comboBox_V->setItemText(1, QCoreApplication::translate("View", "Smooth", nullptr));
        comboBox_V->setItemText(2, QCoreApplication::translate("View", "Sprite", nullptr));

        pushButton_colorV->setText(QCoreApplication::translate("View", "Set color", nullptr));
        label_filename->setText(QCoreApplication::translate("View", "\342\200\242File name: ", nullptr));
        comboBox_L->setItemText(0, QCoreApplication::translate("View", "None", nullptr));
        comboBox_L->setItemText(1, QCoreApplication::translate("View", "Solid", nullptr));
        comboBox_L->setItemText(2, QCoreApplication::translate("View", "Dashed", nullptr));

        pushButton_file->setText(QCoreApplication::translate("View", "Open file", nullptr));
        label_edges->setText(QCoreApplication::translate("View", "Edges", nullptr));
        pushButton_colorL->setText(QCoreApplication::translate("View", "Set color", nullptr));
        label->setText(QCoreApplication::translate("View", "Background color", nullptr));
        label_t->setText(QCoreApplication::translate("View", "Translation", nullptr));
        pushButton_clear->setText(QCoreApplication::translate("View", "Clear", nullptr));
        pushButton_allclear->setText(QCoreApplication::translate("View", "Clear all", nullptr));
    } // retranslateUi

};

namespace Ui {
    class View: public Ui_View {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEW_H
