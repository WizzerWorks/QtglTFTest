// COPYRIGHT_BEGIN
// COPYRIGHT_END

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qgltfreader.h"
#include "qgltfwidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
  public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

  protected:
    void open();
    void about();

  private slots:
    void on_actionOpen_triggered();
    void on_actionAbout_triggered();
    void on_actionSpecification_triggered();

  private:
    Ui::MainWindow *m_ui;
    QglTFReader m_reader;
    QglTFWidget *m_tree;
};

#endif // MAINWINDOW_H
