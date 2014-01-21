// COPYRIGHT_BEGIN
// COPYRIGHT_END

// Include Qt header files.
#include <QFileDialog>
#include <QTextEdit>
#include <QTreeWidgetItem>
#include <QGridLayout>
#include <QMessageBox>

// Include QtglTFTest header files.
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    m_ui(new Ui::MainWindow)
{
    m_ui->setupUi(this);

    // Add QglTFWidget to tree tab.
    QGridLayout *layout = m_ui->treeGridLayout;
    m_tree = new QglTFWidget();
    layout->addWidget(m_tree);
}

MainWindow::~MainWindow()
{
    delete m_ui;
}

void MainWindow::open()
{
    //qDebug("File->Open triggered.");
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open glTF File (OpenGL Transport Format)"), "C:\\Users", tr("glTF Files (*.json)"));
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
               "<p>Copyright &copy; 2014 Wizzer Works"
               "<p>Licensing: The MIT License (MIT)</p>"
               "<p>QtglTFTest is used to exercise "
               "the Wizzer Works QtglTF library."));
}

void MainWindow::on_actionOpen_triggered()
{
    open();
}

void MainWindow::on_actionAbout_triggered()
{
    about();
}

void MainWindow::on_actionSpecification_triggered()
{
}
