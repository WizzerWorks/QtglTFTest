// COPYRIGHT_BEGIN
// COPYRIGHT_END

#ifndef HELPBROWSER_H
#define HELPBROWSER_H

// Include Qt header files.
#include <QTextBrowser>

class QHelpEngine;

class HelpBrowser : public QTextBrowser
{
    Q_OBJECT

  public:
    HelpBrowser(QHelpEngine *helpEngine, QWidget *parent = 0);
    QVariant loadResource(int type, const QUrl &url);

  private:
    QHelpEngine *m_helpEngine;
};

#endif // HELPBROWSER_H
