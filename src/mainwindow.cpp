// COPYRIGHT_BEGIN
// The MIT License (MIT)
//
// Copyright (c) 2014-2019 Wizzer Works
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

// Include Qt header files.
#include <QFile>
#include <QFileDialog>
#include <QTextEdit>
#include <QTreeWidgetItem>
#include <QGridLayout>
#include <QMessageBox>
#include <QSplitter>
#include <QHelpContentModel>
#include <QHelpContentWidget>
#include <QHelpIndexModel>
#include <QHelpIndexWidget>

// Include QtglTF header files.
#include "qgltfvalidator.h"

// Include QtglTFTest header files.
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "helpbrowser.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    m_ui(new Ui::MainWindow),
    m_helpEngine(nullptr),
    m_helpPanel(nullptr)

{
    m_ui->setupUi(this);

    // Add QglTFWidget to tree tab.
    QGridLayout *layout = m_ui->treeGridLayout;
    m_tree = new QglTFWidget();
    layout->addWidget(m_tree);
}

MainWindow::~MainWindow()
{
    if (m_helpEngine != nullptr)
        delete m_helpEngine;
    if (m_helpPanel != nullptr)
        delete m_helpPanel;
    delete m_ui;
}

void MainWindow::open()
{
    //qDebug("File->Open triggered.");
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open glTF File (OpenGL Transport Format)"), "C:\\Users", tr("glTF Files (*.gltf)"));
    if (! fileName.isNull())
    {
        // Attempt to open the glTF file.
        if (! m_reader.open(fileName.toUtf8()))
        {
            qDebug("Unable to open glTF file.");
        } else {
            // Successfully read glTF file.
            QglTFReader::dumpJsonObject(m_reader.getData());

            // Update source editor.
            QString *text = m_reader.toString();
            QTextEdit *sourceEditor = m_ui->textEdit;
            sourceEditor->setText(*text);

            // Update structure editor.
            QJsonObject data = m_reader.getData();
            m_tree->loadData(data);

            // Clean up.
            delete text;
        }
    }
}

void MainWindow::about()
{
    QMessageBox::about(this, tr("About glTF Test"),
            tr("<h2>QtglTFTest 0.1</h2>"
               "<p>Copyright &copy; 2014-2019 Wizzer Works"
               "<p>Licensing: The MIT License (MIT)</p>"
               "<p>QtglTFTest is used to exercise "
               "the Wizzer Works QtglTF library."));
}

bool MainWindow::validate()
{
    bool status = false;

    if (! m_reader.isOpen())
    {
        qDebug("glTF file is not currently open.");
    } else
    {
        // Retrieve the file used to initialize the reader.
        QFile *file = m_reader.getFile();
        QFileInfo info(*file);

        // Translate the file path to a char *.
        QString filepath = info.absoluteFilePath();
        QByteArray utf8BAString = filepath.toUtf8();
        const char *glTFFile = utf8BAString.data();

        QglTFValidator validator;
        status = validator.validate(glTFFile);
    }

    return status;
}

void MainWindow::on_actionOpen_triggered()
{
    open();
}

void MainWindow::on_actionAbout_triggered()
{
    about();
}

void MainWindow::on_actionExit_triggered()
{
    this->close();
}

void MainWindow::on_actionSpecification_triggered()
{
    if (m_helpPanel == nullptr)
    {
        m_helpPanel = new HelpDialog();
        m_helpPanel->open();
    }

    m_helpPanel->show();
}

void MainWindow::on_actionValidate_triggered()
{
    bool status = validate();

    // Todo: display status of validation.
    if (status != true) {
        QMessageBox::information(
            this,
            tr("QtglTF Test"),
            tr("Unable to validate glTF file.") );
    }
}

void MainWindow::displayHelp(QByteArray /*help*/)
{
    // ToDo: Display help here.
}
