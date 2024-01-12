QT       += core gui widgets opengl openglwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17 sdk_no_version_check

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Controller/controller.cpp \
    Model/figure.cpp \
    Model/strategy.cpp \
    Model/command.cpp \
    Model/model.cpp \
    Model/filereader.cpp \
    View/QtGifImage/gifimage/qgifimage.cpp \
    View/QtGifImage/giflib/dgif_lib.c \
    View/QtGifImage/giflib/egif_lib.c \
    View/QtGifImage/giflib/gif_err.c \
    View/QtGifImage/giflib/gif_font.c \
    View/QtGifImage/giflib/gif_hash.c \
    View/QtGifImage/giflib/gifalloc.c \
    View/QtGifImage/giflib/quantize.c \
    View/glview.cpp \
    View/slots.cpp \
    View/record.cpp \
    View/settings.cpp \
    View/view.cpp \
    main.cpp

HEADERS += \
    Controller/controller.h \
    Model/figure.h \
    Model/strategy.h \
    Model/command.h \
    Model/model.h \
    Model/filereader.h \
    View/QtGifImage/gifimage/qgifglobal.h \
    View/QtGifImage/gifimage/qgifimage.h \
    View/QtGifImage/gifimage/qgifimage_p.h \
    View/QtGifImage/giflib/gif_hash.h \
    View/QtGifImage/giflib/gif_lib.h \
    View/QtGifImage/giflib/gif_lib_private.h \
    View/view.h \
    View/glview.h

FORMS += \
    View/view.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
