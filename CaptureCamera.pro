#-------------------------------------------------
#
# Project created by QtCreator 2019-07-09T22:08:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CaptureCamera
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += D:/dir_opencv/opencv_build/install/include \
               D:/dir_opencv/opencv_build/install/include/opencv \
               D:/dir_opencv/opencv_build/install/include/opencv2

LIBS        += D:/dir_opencv/opencv_build/install/x86/mingw/lib/libopencv_core341.dll.a \
               D:/dir_opencv/opencv_build/install/x86/mingw/lib/libopencv_highgui341.dll.a \
               D:/dir_opencv/opencv_build/install/x86/mingw/lib/libopencv_imgproc341.dll.a \
               D:/dir_opencv/opencv_build/install/x86/mingw/lib/libopencv_imgcodecs341.dll.a \
               D:/dir_opencv/opencv_build/install/x86/mingw/lib/libopencv_videoio341.dll.a \
               D:/dir_opencv/opencv_build/install/x86/mingw/lib/libopencv_video341.dll.a \

SOURCES += \
        main.cpp \
        widget.cpp \
    camaraget.cpp

HEADERS += \
        widget.h \
    camaraget.h

FORMS += \
        widget.ui
