
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtglTFTest
TEMPLATE = app

INCLUDEPATH = include \
    ../QtglTF/include

SOURCES += src/main.cpp\
        src/mainwindow.cpp

HEADERS  += include/mainwindow.h

FORMS    += src/mainwindow.ui

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../build-QtglTF-Desktop_Qt_5_0_2_MSVC2010_32bit-Release/release/ -lQtglTF
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../build-QtglTF-Desktop_Qt_5_0_2_MSVC2010_32bit-Debug/debug/ -lQtglTF
else:unix: LIBS += -L$$PWD/../build-QtglTF-Desktop_Qt_5_0_2_MSVC2010_32bit-Debug/ -lQtglTF

INCLUDEPATH += $$PWD/../build-QtglTF-Desktop_Qt_5_0_2_MSVC2010_32bit-Debug/debug
DEPENDPATH += $$PWD/../build-QtglTF-Desktop_Qt_5_0_2_MSVC2010_32bit-Debug/debug

RESOURCES += \
    QtglTFTest.qrc
