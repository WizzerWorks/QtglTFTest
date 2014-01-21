// COPYRIGHT_BEGIN
// COPURIGHT_END

#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow mainWindow;
    mainWindow.setWindowTitle(QString::fromUtf8("glTF Viewer"));
    mainWindow.resize(640, 480);

    mainWindow.show();
    
    return app.exec();
}
