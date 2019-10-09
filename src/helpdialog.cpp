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
#include <QMessageBox>
#include <QHelpContentWidget>
#include <QDebug>

// Include QtglTFText header files.
#include "helpdialog.h"
#include "helpbrowser.h"

HelpDialog::HelpDialog(QWidget *parent)
  : QSplitter(parent), m_width(300), m_height(500), m_helpEngine(NULL)
{
    setMinimumWidth(m_width);
    setMinimumHeight(m_height);
}

HelpDialog::~HelpDialog()
{
    if (m_helpEngine != NULL)
        delete m_helpEngine;
}

void HelpDialog::open()
{
    QHelpContentModel *contentModel;
    QHelpContentWidget *contentWidget;
    HelpBrowser *helpBrowser;

    // Create the help engine if necessary.
    if (m_helpEngine == NULL)
    {
        QFile *file = new QFile(QTGLTFTEST_HELP_COLLECTION);
        if (file->exists()) {
            m_helpEngine = new QHelpEngine(QTGLTFTEST_HELP_COLLECTION);
            bool status = m_helpEngine->setupData();
            //QString collectionFile = m_helpEngine->collectionFile();
            QString docFilename = m_helpEngine->documentationFileName("wizzerworks.com.qtgltftest.1.0");

            QStringList filterAttrs = m_helpEngine->filterAttributes();
            QList<QStringList> filterAttrSets = m_helpEngine->filterAttributeSets("wizzerworks.com.qtgltftest.1.0");

            m_helpEngine->setCurrentFilter("QtglTFTest");
            QString currentFilter = m_helpEngine->currentFilter();

            QList<QUrl> files = m_helpEngine->files("wizzerworks.com.qtgltftest.1.0", filterAttrs);

            contentModel = m_helpEngine->contentModel();
            contentWidget = m_helpEngine->contentWidget();
            helpBrowser = new HelpBrowser(m_helpEngine);

            contentWidget->setMinimumWidth(200);
            contentWidget->setMaximumWidth(200);
            contentWidget->setModel(contentModel);

            connect(contentWidget, SIGNAL(linkActivated(const QUrl &)), helpBrowser, SLOT(setSource(const QUrl &)));

            addWidget(contentWidget);
            addWidget(helpBrowser);

#if 0
            // Get all file references for an identifier.
            QMap<QString, QUrl> links =
                m_helpEngine->linksForIdentifier(QLatin1String("QtglTFTest"));

            // If help is available for this keyword, get the help data
            // of the first file reference.
            if (links.count()) {
                QByteArray helpData = m_helpEngine->fileData(links.constBegin().value());
                // Show the documentation to the user.
                if (! helpData.isEmpty())
                    displayHelp(helpData);
            }
#endif /* 0 */
        } else {
            QMessageBox msg;
            msg.setText(tr("Unable to open help file."));
            msg.setInformativeText(file->fileName());
            msg.exec();
        }
    }
}

void HelpDialog::close()
{
    // Remember current size.
    QSize size = this->size();
    m_width = size.width();
    m_height = size.height();
}

void HelpDialog::closeEvent(QCloseEvent *event)
{
    //qDebug() << "Close event signaled.";
    close();
}

void HelpDialog::show()
{
    setMinimumWidth(m_width);
    setMinimumHeight(m_height);
    QSplitter::show();
}
