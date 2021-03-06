#ifndef QQTMSGBOX_H
#define QQTMSGBOX_H

#include "qqtdialog.h"
#include <qqt-local.h>

namespace Ui {
class QQtMsgBox;
}

/**
 * @brief The QQtMsgBox class
 *
 */
class QQTSHARED_EXPORT QQtMsgBox : public QQtDialog
{
    Q_OBJECT

public:
    explicit QQtMsgBox ( QWidget* parent = 0 );
    virtual ~QQtMsgBox();

    void warning ( QString content );
    void question ( QString content );
    void information ( QString content );

    /*
     * 警告，不可选择
     */
    static int warning ( QWidget* parent = 0, QString content = "" );
    /*
     * 提醒，供用户选择
     */
    static int question ( QWidget* parent = 0, QString content = "" );

protected:
    int _warning ( QString content );
    int _question ( QString content );

private:
    Ui::QQtMsgBox* ui;
    quint32 m_time;
    int delayShow;

    void showYes();
    void showYesAndNo();
    void showNull();

    int widgetW;
    int widgetH;
    int btnW;
    int btnH;
    int botoomH;
    int xSpaceYes;
    int xSpaceYesNo;
    int ySpace;


    // QObject interface
protected:
    void timerEvent ( QTimerEvent* );
};

#endif // QQTMSGBOX_H
