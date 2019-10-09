
QT       += core gui help

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtglTFTest
TEMPLATE = app

INCLUDEPATH = include \
    ../QtglTF/include

SOURCES += src/main.cpp \
    src/mainwindow.cpp \
    src/helpbrowser.cpp \
    src/helpdialog.cpp

HEADERS  += include/mainwindow.h \
    include/helpbrowser.h \
    include/helpdialog.h

FORMS    += src/mainwindow.ui

win32 {
    CONFIG(debug, debug|release) {
        LIBS += -L$$PWD/../build-QtglTF-Desktop_Qt_5_2_1_MSVC2012_OpenGL_64bit-Debug/debug/ -lQtglTF
        INCLUDEPATH += $$PWD/../build-QtglTF-Desktop_Qt_5_2_1_MSVC2012_OpenGL_64bit-Debug/debug
        DEPENDPATH += $$PWD/../build-QtglTF-Desktop_Qt_5_2_1_MSVC2012_OpenGL_64bit-Debug/debug
    } else {
        LIBS += -L$$PWD/../build-QtglTF-Desktop_Qt_5_2_1_MSVC2012_OpenGL_64bit-Release/release/ -lQtglTF
        INCLUDEPATH += $$PWD/../build-QtglTF-Desktop_Qt_5_2_1_MSVC2012_OpenGL_64bit-Release/release
        DEPENDPATH += $$PWD/../build-QtglTF-Desktop_Qt_5_2_1_MSVC2012_OpenGL_64bit-Release/release
    }
}

unix {
    CONFIG(debug, debug|release) {
        LIBS += -L$$PWD/../build-QtglTF-Desktop_Qt_5_13_1_GCC_64bit-Debug -lQtglTF
        INCLUDEPATH += $$PWD/../build-QtglTF-Desktop_Qt_5_13_1_GCC_64bit-Debug
        DEPENDPATH += $$PWD/../build-QtglTF-Desktop_Qt_5_8_0_GCC_64bit-Debug
    } else {
        LIBS += -L$$PWD/../build-QtglTF-Desktop_Qt_5_13_1_GCC_64bit-Release -lQtglTF
        INCLUDEPATH += $$PWD/../build-QtglTF-Desktop_Qt_5_13_1_GCC_64bit-Release
        DEPENDPATH += $$PWD/../build-QtglTF-Desktop_Qt_5_13_1_GCC_64bit-Release
    }
}

RESOURCES += \
    QtglTFTest.qrc

CONFIG(release, debug|release): DESTDIR = $$OUT_PWD/release
CONFIG(debug, debug|release): DESTDIR = $$OUT_PWD/debug

install_it.path = $$DESTDIR
install_it.files += $$PWD/doc/html/QtglTFTest.qhc $$PWD/doc/html/glTF.qch

INSTALLS += install_it
