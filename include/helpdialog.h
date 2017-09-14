// COPYRIGHT_BEGIN
// The MIT License (MIT)
//
// Copyright (c) 2014 Wizzer Works
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of
// this software and associated documentation files (the "Software"), to deal in
// the Software without restriction, including without limitation the rights to
// use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
// the Software, and to permit persons to whom the Software is furnished to do so,
// subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
// FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
// COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
// IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
// COPYRIGHT_END

#ifndef HELPDIALOG_H
#define HELPDIALOG_H

// Include Qt header files.
#include <QSplitter>
#include <QHelpEngine>

// Todo: need a better way to find help file (based on environment var).
#ifdef Q_OS_WIN
#define QTGLTFTEST_HELP_COLLECTION "C:\\Users\\msm\\tmp\\QtglTFTest.qhc"
#else
#define QTGLTFTEST_HELP_COLLECTION "/home/msm/tmp/QtglTFTest.qhc"
#endif

class HelpDialog : public QSplitter
{
    Q_OBJECT

  public:
    HelpDialog(QWidget *parent = 0);
    ~HelpDialog();

    void open();
    void close();
    void show();

    void closeEvent(QCloseEvent *event);

  private:
    int m_width;
    int m_height;

    QHelpEngine *m_helpEngine;

};

#endif // HELPDIALOG_H
