#ifndef QQTTABBAR_H
#define QQTTABBAR_H

#include <QTabBar>
#include <QList>
#include "qqtdefine.h"

class QQTTabBar : public QTabBar
{
    Q_OBJECT

public:
    explicit QQTTabBar(QWidget *parent = 0);

    void tabPixmap(int index, QImage &icon, QImage &iconSel);
    void setTabPixmap(int index, const QString& icon = QString(), const QString &iconSel = QString());

protected:
    void paintEvent(QPaintEvent *);
    inline bool verticalTabs();

public slots:

private:
    QList<TBtnIconTable> iconList;
};

#endif // QQTTABBAR_H
