// COPYRIGHT_BEGIN
// COPYRIGHT_END

// Include Qt header files.
#include <QHelpEngine>

// Include QtglTFTest header files.
#include "helpbrowser.h"

HelpBrowser::HelpBrowser(QHelpEngine *helpEngine, QWidget *parent)
  : QTextBrowser(parent), m_helpEngine(helpEngine)
{
}

QVariant HelpBrowser::loadResource(int type, const QUrl &url)
{
    if (url.scheme() == "qthelp")
        return QVariant(m_helpEngine->fileData(url));
    else
        return QTextBrowser::loadResource(type, url);
}
