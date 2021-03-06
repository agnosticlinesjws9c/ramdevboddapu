#ifndef QQTTABWIDGET_H
#define QQTTABWIDGET_H

#include <QTabWidget>
#include "qqt-local.h"

/**
 * @brief The QQtTabWidget class
 * 用于解决QtTabWidget接口上的错误
 * 这个类，没有实际使用意义，它的子类才有，在exquisite里面。
 */
class QQTSHARED_EXPORT QQtTabWidget : public QTabWidget
{
    Q_OBJECT

public:
    explicit QQtTabWidget ( QWidget* parent = 0 );
    virtual ~QQtTabWidget();
    /**
     * @brief setObjectName
     * 为了设置tabbar的objectname，内部的设置不清晰。
     * 子类必须override一次，否则会找不到自己的tabbar
     * override 不支持c++ 多继承中的其中一个父类里的函数? 似乎不支持父类中不带virtual的函数
     * @param name
     */
    virtual void setObjectName ( const QString& name ) /*override*/;
    /**
     * @brief setToolTipDuration
     * bug? unset cause compiler error...
     * 5.8.5 no setToolTipDuration so cl err
     * >5.8.5 no need this override
     * @param msec
     */
    //virtual void setToolTipDuration(int msec) /*override*/ { return QTabWidget::setToolTipDuration(msec) ; }
    /**
     * @brief localTabBar
     * 在setTabBar以后，系统tabBar和这个Bar不一样。
     * 返回本地设置的tabbar，给子类用的，QQtTabWidget返回系统tabBar，不可用！
     * 用于eventfilter
     * @return
     */
    virtual QTabBar* localTabBar() const { return QTabWidget::tabBar(); }
    /**
     * @brief tabBar
     * 用于eventfilter
     * Qt4.8.7 protected公开为public
     * @return
     */
    virtual QTabBar* tabBar() const /*override*/ { return QTabWidget::tabBar(); }
    /**
     * @brief setTabBar
     * 这个函数是个炸弹，必须在子类的构造函数中，带ui的在setupUI之前，调动，否则不起作用。
     * protected公开为public
     * @param b
     */
    virtual void setTabBar ( QTabBar* b ) /*override*/ { return QTabWidget::setTabBar ( b ); }

private:
};

#endif // QQTTABWIDGET_H
