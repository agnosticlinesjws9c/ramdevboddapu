#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <qqtcore.h>

// 2021年4月1日
// BAD EXPORT FOUND [MSVC2015]
// MSVC2015，不使用QQtOrderedDictionary就可以了，其他模块正常。

// 2021年4月23日
// 已解决。
// MSVC2015，QQtOrderedDictionary导出正常。


#include <qqtorderedmap.h>
#include <qqtordereddictionary.h>

#include <qqtdicthelper.h>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    pline() << "aaa";
    QQtOrderedDictionary d2;
    d2["b"] = 'b';
    d2["a"] = 'a';
    d2["c"] = "This is a string.";
    d2["d"] = QQtOrderedDictionary();
    d2["d"]["d_1"] = "What? coming?";

    pline() << d2;
    pline() << d2["d"];
}

MainWindow::~MainWindow()
{
    delete ui;
}
