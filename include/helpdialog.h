// COPYRIGHT_BEGIN
// COPYRIGHT_END

#ifndef HELPDIALOG_H
#define HELPDIALOG_H

// Include Qt header files.
#include <QSplitter>
#include <QHelpEngine>

#define QTGLTFTEST_HELP_COLLECTION "C:\\Users\\msm\\tmp\\QtglTFTest.qhc"

class HelpDialog : public QSplitter
{
    Q_OBJECT

  public:
    HelpDialog(QWidget *parent = 0);
    ~HelpDialog();

    void init();

  private:
    int m_width;
    int m_height;

    QHelpEngine *m_helpEngine;

};

#endif // HELPDIALOG_H
