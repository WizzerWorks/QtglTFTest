// COPYRIGHT_BEGIN
// COPYRIGHT_END

#include <QFile>
#include <QMessageBox>
#include <QHelpContentWidget>

#include "helpdialog.h"
#include "helpbrowser.h"

HelpDialog::HelpDialog(QWidget *parent)
  : QSplitter(parent), m_width(300), m_height(500), m_helpEngine(NULL)
{
    this->setMinimumWidth(m_width);
    this->setMinimumHeight(m_height);
}

HelpDialog::~HelpDialog()
{
    if (m_helpEngine != NULL)
        delete m_helpEngine;
}

void HelpDialog::init()
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
