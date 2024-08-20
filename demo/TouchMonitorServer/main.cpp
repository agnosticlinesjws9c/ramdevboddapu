#include "mainwindow.h"
#include <QQtApplication>
#include <qqtosdwidget.h>
#include <testwidget.h>
#include <qqtosdform.h>

int main ( int argc, char* argv[] )
{
    QQtApplication a ( argc, argv );

    //其实功能很简单，
    //收到手机通过网络、或者蓝牙、或者USB线发来的操作信号以后，服务器进行POS转换，模拟点击。
    //起初，用于手机控制腾讯手游助手里的王者荣耀游戏。

    MainWindow w;
    //TestWidget w;
    //QQtOsdForm w;
    w.show();
    //w.setWindowOpacity ( 1 );
    //w.setWindowFlags ( Qt::FramelessWindowHint );
    //w.setAttribute ( Qt::WA_TranslucentBackground );

    return a.exec();
}
